/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:14:12 by curry-san         #+#    #+#             */
/*   Updated: 2025/03/27 09:46:16 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_tex	get_texture(t_game *game, t_ray *ray)
{
	return game->north;
	if (ray->side == 1)
	{
		if (ray->raydiry > 0)
			return (game->south);
		return (game->north);
	}
	else if (ray->side == 0)
	{
		if (ray->raydirx > 0)
			return (game->east);
		return (game->west);
	}
}

void	draw_texture(t_game *game, t_ray *ray)
{
	t_tex	texture;
	(void)game;
	texture = get_texture(game, ray);
	(void)texture;
	return ;
}