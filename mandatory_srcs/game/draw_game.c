/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/25 08:54:40 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel(t_game *game, int x, int y, int color)
{
	int	index;

	index = y * game->key_img.size_line + x * game->key_img.bpp / 8;
	game->key_img.addr[index] = color & 0xFF;
	game->key_img.addr[index + 1] = (color >> 8) & 0xFF;
	game->key_img.addr[index + 2] = (color >> 16) & 0xFF;
}

void	draw_line(t_game *game, int start, int end, int x, int color)
{
	while (start < end)
	{
		put_pixel(game, x, start, color);
		start++;
	}
}

int	draw_wall(t_game *game)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	int	x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		ray = init_ray(game, x);
		dda(&ray, game);
		line_height = (int)(HEIGHT / ray.perpwalldist);
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		if (ray.side == 1)
			color = 0xFF0000; // Red for y-side walls
		else
			color = 0x00FF00; // Green for x-side walls
		draw_line(game, draw_start, draw_end, x, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->key_img.img, 0, 0);
	return (0);
}
