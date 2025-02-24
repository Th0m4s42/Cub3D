/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:33 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/24 12:47:39 by curry-san        ###   ########.fr       */
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
	else if (keycode == KEY_LEFT)
		printf("keyLEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("keyRIGHT\n");
	else if (keycode == KEY_W)
		printf("key_W\n");
	else if (keycode == KEY_A)
		printf("key_A\n");
	else if (keycode == KEY_S)
		printf("key_S\n");
	else if (keycode == KEY_D)
		printf("key_D\n");
	return (0);
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(game->mlx);
	else if (keycode == KEY_LEFT)
		printf("keyLEFT\n");
	else if (keycode == KEY_RIGHT)
		printf("keyRIGHT\n");
	else if (keycode == KEY_W)
		printf("key_W\n");
	else if (keycode == KEY_A)
		printf("key_A\n");
	else if (keycode == KEY_S)
		printf("key_S\n");
	else if (keycode == KEY_D)
		printf("key_D\n");
	return (0);
}

int		cross_event(t_game *game)
{
	printf("Trying to cross close windows\n");
	mlx_loop_end(game->mlx);
	return (0);
}

void	init_key_event(t_game *game)
{
	(void)game;
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win, 17, 1L << 19, &cross_event, game);
	// mlx_set_font(game->mlx, game->win,
	// 	"-sony-fixed-medium-r-normal--24-170-100-100-c-120-iso8859-1");
}
