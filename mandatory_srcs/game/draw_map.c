/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:39:16 by curry-san         #+#    #+#             */
/*   Updated: 2025/03/02 00:27:12 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	draw_player(t_game *game)
{
	(void)game;//player utile quand on voudra le sens;
	
	int	x;
	int	y;

	y = 0;//(HEIGHT_MAP / 2) - 10;

	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			put_pixel(&game->map_img, y + (WIDTH_MAP / 2) - 3, x + (HEIGHT_MAP / 2) - 3, 0xFF0000);
			x++;
		}
		y++;
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
		pos_x = x_pl - (((WIDTH_MAP / 2) - width) / 10); //CEST PAS LE BON CALCUL PUTIN, des bisous
	else
		pos_x = x_pl + ((width - (WIDTH_MAP / 2)) / 10);
	/*-----------------------*/
	if (height < (HEIGHT_MAP / 2))
		pos_y = y_pl - (((HEIGHT_MAP / 2) - height) / 10);
	else
		pos_y = y_pl + ((height - (HEIGHT_MAP / 2)) / 10);
	/*-----------------------*/
	if (pos_y >= ft_tablen(map) || pos_x >= ft_strlen(map[pos_y]))
		return (false);
	if (!map[pos_y][pos_x] || map[pos_y][pos_x] == '\n')
	return (false);
	if (pos_y < 0 || pos_x < 0 || map[pos_y][pos_x] == ' ' || map[pos_y][pos_x] == '1')
		return (false);
	return (true);
}

void	draw_map(t_game *game)
{
	int	start = 0;
	int	x = 0;
	if (game->player.key_map == false)
		return ;
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
