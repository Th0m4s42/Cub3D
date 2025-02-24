/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:03:07 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/24 12:39:56 by thbasse          ###   ########.fr       */
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
}

void	dda(t_ray *ray, t_game *game)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			side = 1;
		}
		if (game->map[ray->mapx][ray->mapy] == '1')
			hit = 1;
	}
	if (side == 0)
		ray->perpwalldist = (ray->mapx - game->player.x + (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - game->player.y + (1 - ray->stepy) / 2) / ray->raydiry;
	// ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	// ray->drawstart = -ray->lineheight / 2 + HEIGHT / 2;
	// if (ray->drawstart < 0)
	// 	ray->drawstart = 0;
	// ray->drawend = ray->lineheight / 2 + HEIGHT / 2;
	// if (ray->drawend >= HEIGHT)
	// 	ray->drawend = HEIGHT - 1;
}
