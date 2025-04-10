/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:03:07 by thbasse           #+#    #+#             */
/*   Updated: 2025/04/03 14:25:14 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_dda(t_ray *ray, t_game *game)
{
	ray->mapx = (int)game->player.x;
	ray->mapy = (int)game->player.y;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->player.x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - game->player.x) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->player.y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - game->player.y) * ray->deltadisty;
	}
}

t_ray	init_ray(t_game *game, int x)
{
	t_ray	ray;

	ray.camerax = 2 * x / (double)WIDTH - 1;
	ray.raydirx = game->player.dirx + game->player.planex * ray.camerax;
	ray.raydiry = game->player.diry + game->player.planey * ray.camerax;
	ray.mapx = (int)game->player.x;
	ray.mapy = (int)game->player.y;
	ray.deltadistx = fabs(1 / ray.raydirx);
	ray.deltadisty = fabs(1 / ray.raydiry);
	ray.hit = 0;
	ray.side = 0;
	init_dda(&ray, game);
	return (ray);
}

void	dda(t_ray *ray, t_game *game)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (game->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}
