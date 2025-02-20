/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:33 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/20 12:39:33 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_key_event(t_game *game)
{
	// mlx_hook(data->mlx_data.win, 2, 1L << 0, /*&key_event*/, game);
	mlx_hook(data->mlx_data.win, 17, 1L << 19, cross_event, game);
	mlx_set_font(data->mlx_data.mlx, data->mlx_data.win,
		"-sony-fixed-medium-r-normal--24-170-100-100-c-120-iso8859-1");
}

// void	key_event(int keycode, t_game *game)
// {
	
// }

void	cross_event(t_game *game)
{
	printf("Trying to cross close windows\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}
