/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:39:16 by curry-san         #+#    #+#             */
/*   Updated: 2025/03/19 10:32:45 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	draw_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			put_pixel(&game->map_img,
				y + (WIDTH_MAP / 2) - 3, x + (HEIGHT_MAP / 2) - 3, 0xFF0000);
			x++;
		}
		y++;
	}
	// point de visuel
	if (game->player.dirx > 0.0)
	{
		for (int a = 0; a < 20; a++)
		{
			put_pixel(&game->map_img,
				(WIDTH_MAP / 2) + a, (HEIGHT_MAP / 2), 0xFF0000);
		}
	}
	else if (game->player.dirx < 0.0)
	{
		for (int a = 0; a < 20; a++)
		{
			put_pixel(&game->map_img,
				(WIDTH_MAP / 2) - a, (HEIGHT_MAP / 2), 0xFF0000);
		}
	}
	else if (game->player.diry < 0.0)
	{
		for (int a = 0; a < 20; a++)
		{
			put_pixel(&game->map_img,
				(WIDTH_MAP / 2), (HEIGHT_MAP / 2) - a, 0xFF0000);
		}
	}
	else
	{
		for (int a = 0; a < 20; a++)
		{
			put_pixel(&game->map_img,
				(WIDTH_MAP / 2), (HEIGHT_MAP / 2) + a, 0xFF0000);
		}
	}
	
}

static bool	check_wall_map(t_player *player, char **map, int width, int height)
{
	float	x_pl;
	float	y_pl;
	float	pos_x;
	float	pos_y;

	x_pl = player->x;
	y_pl = player->y;
	if (width < (WIDTH_MAP / 2.0))
		pos_x = x_pl - (((WIDTH_MAP / 2.0) - width) / 10.0);
	else
		pos_x = x_pl + ((width - (WIDTH_MAP / 2.0)) / 10.0);
	if (height < (HEIGHT_MAP / 2.0))
		pos_y = y_pl - (((HEIGHT_MAP / 2.0) - height) / 10.0);
	else
		pos_y = y_pl + ((height - (HEIGHT_MAP / 2.0)) / 10.0);
	if ((size_t)pos_y >= ft_tablen(map)
		|| (size_t)pos_x >= ft_strlen(map[(int)pos_y]))
		return (false);
	if (!map[(int)pos_y][(int)pos_x] || map[(int)pos_y][(int)pos_x] == '\n')
		return (false);
	if (pos_y < 0 || pos_x < 0 || map[(int)pos_y][(int)pos_x] == ' '
			|| map[(int)pos_y][(int)pos_x] == '1')
		return (false);
	return (true);
}

void	draw_map(t_game *game)
{
	int	start;
	int	x;

	if (game->player.key_map == false)
		return ;
	x = 0;
	while (x < WIDTH_MAP)
	{
		start = 0;
		while (start < HEIGHT_MAP)
		{
			if (check_wall_map(&game->player, game->map, x, start) == true)
				put_pixel(&game->map_img, x, start, 0x343434);
			else
				put_pixel(&game->map_img, x, start, 0x999999);
			start++;
		}
		x++;
	}
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->map_img.img, 10, 10);
}
