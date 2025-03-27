/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:14:12 by curry-san         #+#    #+#             */
/*   Updated: 2025/03/27 22:20:19 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	index;

	index = y * img->size_line + x * img->bpp / 8;
	img->addr[index] = color & 0xFF;
	img->addr[index + 1] = (color >> 8) & 0xFF;
	img->addr[index + 2] = (color >> 16) & 0xFF;
}

int rgb_to_int(int r, int g, int b)
{
	int color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

// t_tex	get_texture(t_game *game, t_ray *ray)
// {
// 	return game->north;
// 	if (ray->side == 1)
// 	{
// 		if (ray->raydiry > 0)
// 			return (game->south);
// 		return (game->north);
// 	}
// 	else if (ray->side == 0)
// 	{
// 		if (ray->raydirx > 0)
// 			return (game->east);
// 		return (game->west);
// 	}
// }
