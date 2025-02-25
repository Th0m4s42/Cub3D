/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:03:07 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/25 07:37:14 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_ray	init_ray(t_game *game)
{
	t_ray	ray;

	ray.mapy = (int)game->player.y;
	ray.mapx = (int)game->player.x;
	ray.camerax = 2 * ray.mapx / (double)WIDTH - 1;
	ray.raydirx = game->player.dirx + game->player.planex * ray.camerax;
	ray.raydiry = game->player.diry + game->player.planey * ray.camerax;
	ray.deltadistx = fabs(1 / ray.raydirx);
	ray.deltadisty = fabs(1 / ray.raydiry);
	ray.hit = 0;
	ray.perpwalldist = 0;
	ray.side = 0;
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
	if (ray->side == 0) // ===> effet fisheye
		ray->perpwalldist = (ray->mapx - game->player.x + (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - game->player.y + (1 - ray->stepy) / 2) / ray->raydiry;
}
