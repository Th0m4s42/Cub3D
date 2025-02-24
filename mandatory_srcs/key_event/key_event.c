/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:33 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/24 12:54:04 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// void	key_event(int keycode, t_game *game)
// {
	
// }

int		key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(game->mlx);
	else if (keycode == CAMERA_LEFT)
		printf("camera LEFT\n");
	else if (keycode == CAMERA_RIGHT)
		printf("camera RIGHT\n");
	else if (keycode == KEY_UP)
		printf("key_UP\n");
	else if (keycode == KEY_LEFT)
		printf("key_LEFT\n");
	else if (keycode == KEY_DOWN)
		printf("key_DOWN\n");
	else if (keycode == KEY_RIGHT)
		printf("key_RIGHT\n");
	return (0);
}


int		cross_event(t_game *game)
{
	printf("MLX LOOP END\n");
	mlx_loop_end(game->mlx);
	return (0);
}

void	init_key_event(t_game *game)
{
	(void)game;
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	// mlx_hook(game->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win, 17, 1L << 19, &cross_event, game);
	// mlx_set_font(game->mlx, game->win,
	// 	"-sony-fixed-medium-r-normal--24-170-100-100-c-120-iso8859-1");
}
