/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/24 17:06:45 by curry-san        ###   ########.fr       */
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

int	draw_wall(t_game *game, int x)
{
	(void)x;
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	t_ray	ray;

	ray = init_ray(game);
	line_height = (int)(HEIGHT / ray.perpwalldist);
	// printf("line_height = %d\n", line_height);
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
	(void)color;

	// draw_line(game, draw_start, draw_end, x, color);
	return (0);
}
