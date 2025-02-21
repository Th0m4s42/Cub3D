/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:30:09 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/21 12:23:11 by thbasse          ###   ########.fr       */
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
					player.x = x;
					player.y = y;
				}
				x++;
			}
			y++;
		}
	player.dirx = 0;
	player.diry = 0;
	return (player);
}

void	init_player(t_game *game)
{
	game->player = player_start(game->map);
	if(game->map[game->player.y][game->player.x] == 'N')
		game->player.diry -= 1;
	else if(game->map[game->player.y][game->player.x] == 'S')
		game->player.diry += 1;
	else if(game->map[game->player.y][game->player.x] == 'E')
		game->player.dirx += 1;
	else if(game->map[game->player.y][game->player.x] == 'W')
		game->player.dirx -= 1;
}
