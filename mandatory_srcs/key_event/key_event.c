/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:33 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/24 13:04:09 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int		key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(game->mlx);
	else if (keycode == CAMERA_LEFT)
		game->player.camera_left = true;
	else if (keycode == CAMERA_RIGHT)
		game->player.camera_right = true;
	else if (keycode == KEY_UP)
		game->player.key_up = true;
	else if (keycode == KEY_LEFT)
		game->player.key_left = true;
	else if (keycode == KEY_DOWN)
		game->player.key_down = true;
	else if (keycode == KEY_RIGHT)
		game->player.key_right = true;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == CAMERA_LEFT)
		game->player.camera_left = false;
	else if (keycode == CAMERA_RIGHT)
		game->player.camera_right = false;
	else if (keycode == KEY_UP)
		game->player.key_up = false;
	else if (keycode == KEY_LEFT)
		game->player.key_left = false;
	else if (keycode == KEY_DOWN)
		game->player.key_down = false;
	else if (keycode == KEY_RIGHT)
		game->player.key_right = false;
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
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win, 17, 1L << 19, &cross_event, game);
}
