/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:12:35 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/18 18:08:30 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	w_key(t_game *game)
{
	if (game->map[(int)(game->player.y - game->player.diry * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y -= game->player.diry * MOVE_SPEED;
	if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.dirx * MOVE_SPEED)] != '1')
		game->player.x += game->player.dirx * MOVE_SPEED;
	printf("player_X = %f, player_Y = %f\n", game->player.x, game->player.y);
	// printf("dirX = %f, dirY = %f\n", game->player.dirx, game->player.diry);
	// printf("planeX = %f, planeY = %f\n", game->player.planex, game->player.planey);
}

void	s_key(t_game *game)
{
	if (game->map[(int)(game->player.y + game->player.diry * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y += game->player.diry * MOVE_SPEED;
	if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.dirx * MOVE_SPEED)] != '1')
		game->player.x -= game->player.dirx * MOVE_SPEED;
}

void	a_key(t_game *game)
{
	if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.planey * MOVE_SPEED)] != '1')
		game->player.x -= game->player.planey * MOVE_SPEED;
	if (game->map[(int)(game->player.y - game->player.planex * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y -= game->player.planex * MOVE_SPEED;
}

void	d_key(t_game *game)
{
	if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.planey * MOVE_SPEED)] != '1')
		game->player.x += game->player.planey * MOVE_SPEED;
	if (game->map[(int)(game->player.y + game->player.planex * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y += game->player.planex * MOVE_SPEED;
}
