/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/27 14:45:08 by ckenaip          ###   ########.fr       */
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

void	draw_line(t_game *game, int start, int end, int x, int color)
{
	while (start < end)
	{
		put_pixel(&game->key_img, x, start, color);
		start++;
	}
}

void	map_to_img(t_game *game)
{
	int	start = 0;
	int	x = 0;
	while (x < WIDTH_MAP)
	{
		start = 0;
		while (start < HEIGHT_MAP)
		{
			// put_pixel(&game->map_img, x, start, 0xFF0000);
			put_pixel(&game->map_img, x, start, 0xFFFF00);
			start++;
		}
		x++;
	}
	// draw_
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
	map_to_img(game);
	mlx_put_image_to_window(game->mlx, game->win, game->key_img.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->map_img.img, 10, 10);
	return (0);
}
