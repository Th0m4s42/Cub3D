/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:12:35 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/06 17:08:54 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	w_key(t_game *game)
{
	if (game->map[(int)(game->player.y + game->player.diry * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y += game->player.diry * MOVE_SPEED;
	if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.dirx * MOVE_SPEED)] != '1')
		game->player.x += game->player.dirx * MOVE_SPEED;
}

void	s_key(t_game *game)
{
	if (game->map[(int)(game->player.y - game->player.diry * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y -= game->player.diry * MOVE_SPEED;
	if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.dirx * MOVE_SPEED)] != '1')
		game->player.x -= game->player.dirx * MOVE_SPEED;
}

void	a_key(t_game *game)
{
	if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.diry * MOVE_SPEED)] != '1')
		game->player.x -= game->player.diry * MOVE_SPEED;
	if (game->map[(int)(game->player.y - game->player.dirx * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y -= game->player.dirx * MOVE_SPEED;
}

void	d_key(t_game *game)
{
	if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.diry * MOVE_SPEED)] != '1')
		game->player.x += game->player.diry * MOVE_SPEED;
	if (game->map[(int)(game->player.y - game->player.dirx * MOVE_SPEED)][(int)(game->player.x)] != '1')
		game->player.y -= game->player.dirx * MOVE_SPEED;
}
