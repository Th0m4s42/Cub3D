/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:03:07 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/10 16:11:42 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_ray	init_ray(t_game *game, int x)
{
	t_ray	ray;

	ray.camerax = 2 * x / (double)WIDTH - 1;
	ray.raydirx = game->player.dirx + game->player.planex * ray.camerax;
	ray.raydiry = game->player.diry + game->player.planey * ray.camerax;
	ray.mapx = (int)game->player.x;
	ray.mapy = (int)game->player.y;
	if (ray.raydiry == 0)
		ray.raydiry = 1e30;
	else
		ray.deltadisty = fabs(1 / ray.raydiry);
	if (ray.raydirx == 0)
		ray.raydirx = 1e30;
	else
		ray.deltadistx = fabs(1 / ray.raydirx);
	ray.hit = 0;
	ray.side = 0;
	if (ray.raydirx < 0)
	{
		ray.stepx = -1;
		ray.sidedistx = (ray.mapx - game->player.x) * ray.deltadistx;
	}
	else
	{
		ray.stepx = 1;
		ray.sidedistx = (game->player.x + 1.0 - ray.mapx) * ray.deltadistx;
	}
	if (ray.raydiry < 0)
	{
		ray.stepy = -1;
		ray.sidedisty = (ray.mapy - game->player.y) * ray.deltadisty;
	}
	else
	{
		ray.stepy = 1;
		ray.sidedisty = (game->player.y + 1.0 - ray.mapy) * ray.deltadisty;
	}
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
		if (game->map[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}
