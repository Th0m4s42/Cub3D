/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:48:59 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/27 21:05:43 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(-ROTATE_SPEED)
		- game->player.diry * sin(-ROTATE_SPEED);
	game->player.diry = old_dir_x * sin(-ROTATE_SPEED)
		+ game->player.diry * cos(-ROTATE_SPEED);
	old_plane_x = game->player.planex;
	game->player.planex = game->player.planex * cos(-ROTATE_SPEED)
		- game->player.planey * sin(-ROTATE_SPEED);
	game->player.planey = old_plane_x * sin(-ROTATE_SPEED)
		+ game->player.planey * cos(-ROTATE_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(ROTATE_SPEED)
		- game->player.diry * sin(ROTATE_SPEED);
	game->player.diry = old_dir_x * sin(ROTATE_SPEED)
		+ game->player.diry * cos(ROTATE_SPEED);
	old_plane_x = game->player.planex;
	game->player.planex = game->player.planex * cos(ROTATE_SPEED)
		- game->player.planey * sin(ROTATE_SPEED);
	game->player.planey = old_plane_x * sin(ROTATE_SPEED)
		+ game->player.planey * cos(ROTATE_SPEED);
}
