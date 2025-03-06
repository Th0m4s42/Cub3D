/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:12:35 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/06 08:23:21 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	w_key(t_game *game)
{
	if (game->player.key_up)
	{
		if (game->map[(int)(game->player.y + game->player.diry * MOVE_SPEED)][(int)(game->player.x)] != '1')
			game->player.y += game->player.diry * MOVE_SPEED;
		if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.dirx * MOVE_SPEED)] != '1')
			game->player.x += game->player.dirx * MOVE_SPEED;
	}
}

void	s_key(t_game *game)
{
	if (game->player.key_down)
	{
		if (game->map[(int)(game->player.y - game->player.diry * MOVE_SPEED)][(int)(game->player.x)] != '1')
			game->player.y -= game->player.diry * MOVE_SPEED;
		if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.dirx * MOVE_SPEED)] != '1')
			game->player.x -= game->player.dirx * MOVE_SPEED;
	}
}

void	a_key(t_game *game)
{
	if (game->player.key_left)
	{
		if (game->map[(int)(game->player.y)][(int)(game->player.x - game->player.diry * MOVE_SPEED)] != '1')
			game->player.x -= game->player.diry * MOVE_SPEED;
		if (game->map[(int)(game->player.y + game->player.dirx * MOVE_SPEED)][(int)(game->player.x)] != '1')
			game->player.y += game->player.dirx * MOVE_SPEED;
	}
}
void	d_key(t_game *game)
{
	if (game->player.key_right)
	{
		if (game->map[(int)(game->player.y)][(int)(game->player.x + game->player.diry * MOVE_SPEED)] != '1')
			game->player.x += game->player.diry * MOVE_SPEED;
		if (game->map[(int)(game->player.y - game->player.dirx * MOVE_SPEED)][(int)(game->player.x)] != '1')
			game->player.y -= game->player.dirx * MOVE_SPEED;
	}
}
