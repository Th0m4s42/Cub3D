/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/28 14:03:19 by ckenaip          ###   ########.fr       */
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

static bool	check_wall_map(t_player *player, char **map, int width, int height)
{
	int	x_pl;
	int	y_pl;
	int	pos_x;
	int	pos_y;

	x_pl = player->x;
	y_pl = player->y;
	/*-----------------------*/
	if (width < (WIDTH_MAP / 2))
		pos_x = x_pl - (width / 10);
	else
		pos_x = x_pl + (width / 10);
	/*-----------------------*/
	if (height < (HEIGHT_MAP / 2))
		pos_y = y_pl - (height / 2);
	else
		pos_y = y_pl + (height / 2);
	/*-----------------------*/
	if (pos_x > 9 || pos_y > 9)
		return (false);
	// printf("x = %d, y = %d\n", pos_x, pos_y);
	if (pos_y < 0 || pos_y < 0 || map[pos_y][pos_x] == ' ' || map[pos_y][pos_x] == '1')
		return (false);
	return (true);
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
			if (check_wall_map(&game->player, game->map, x, start) == true)
				put_pixel(&game->map_img, x, start, 0x0000FF);
			else
				put_pixel(&game->map_img, x, start, 0xFFFF00);
			start++;
		}
		x++;
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
	// map_to_img(game);
	mlx_put_image_to_window(game->mlx, game->win, game->key_img.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->map_img.img, 10, 10);
	return (0);
}
