/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:03:07 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/18 18:57:32 by thbasse          ###   ########.fr       */
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
	ray.deltadisty = fabs(1 / ray.raydiry);
	ray.deltadistx = fabs(1 / ray.raydirx);
	ray.hit = 0;
	ray.side = 0;
	if (ray.raydirx < 0)
	{
		ray.stepx = -1;
		ray.sidedistx = (game->player.x - ray.mapx) * ray.deltadistx;
	}
	else
	{
		ray.stepx = 1;
		ray.sidedistx = (ray.mapx + 1.0 - game->player.x) * ray.deltadistx;
	}
	if (ray.raydiry < 0)
	{
		ray.stepy = -1;
		ray.sidedisty = (game->player.y - ray.mapy) * ray.deltadisty;
	}
	else
	{
		ray.stepy = 1;
		ray.sidedisty = (ray.mapy + 1.0 - game->player.y) * ray.deltadisty;
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
		if (game->map[ray->mapy][ray->mapx] > '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}
