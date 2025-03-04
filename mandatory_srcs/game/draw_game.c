/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/04 17:05:57 by thbasse          ###   ########.fr       */
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

static int rgb_to_int(int r, int g, int b)
{
	int color;
	
	color = 0;
	color |= b * 255;
	color |= (g * 255) << 8;
	color |= (r * 255) << 16;
	return (color);
}

static void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&game->key_img, x, y, rgb_to_int(game->visual.cell_r, game->visual.cell_g, game->visual.cell_b));
			x++;
		}
		y++;
	}
	y = HEIGHT / 2;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&game->key_img, x, y, rgb_to_int(game->visual.floor_r, game->visual.floor_g, game->visual.floor_b));
			x++;
		}
		y++;
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
	if (game->player.key_up == true)
		game->player.y -= 0.01;
	if (game->player.key_down == true)
		game->player.y += 0.01;
	if (game->player.key_left == true)
		game->player.x -= 0.01;
	if (game->player.key_right == true)
		game->player.x += 0.01;
	// printf("player_X = %f, player_Y = %f\n", game->player.x, game->player.y);
	draw_floor_ceiling(game);
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
		else if (ray.side == 0)
			color = 0x00FF00; // Green for x-side walls
		draw_line(game, draw_start, draw_end, x, color);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->key_img.img, 0, 0);
	draw_map(game);// APPUIE SUR M !
	return (0);
}
