/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:30:09 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/24 08:56:57 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_player	player_start(char **map)
{
	int	x;
	int	y;
	t_player	player;

	y = 0;
	while (map[y] && map[y + 1])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
				{
					player.x = (float)x;
					player.y = (float)y;
				}
				x++;
			}
			y++;
		}
	player.dirx = 0.0;
	player.diry = 0.0;
	return (player);
}

void	init_player(t_game *game)
{
	game->player = player_start(game->map);
	if(game->map[(int)game->player.y][(int)game->player.x] == 'N')
		game->player.diry -= 1;
	else if(game->map[(int)game->player.y][(int)game->player.x] == 'S')
		game->player.diry += 1;
	else if(game->map[(int)game->player.y][(int)game->player.x] == 'E')
		game->player.dirx += 1;
	else if(game->map[(int)game->player.y][(int)game->player.x] == 'W')
		game->player.dirx -= 1;
	game->player.planex = 0.0;
	game->player.planey = 0.66;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_right = false;
	game->player.key_left = false;
}
