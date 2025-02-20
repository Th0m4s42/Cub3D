/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:30:09 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/20 13:00:12 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	player_view(int dirx, int diry, char orientation)
{
	if (orientation == 'N')
	{
		dirx = 0;
		diry = -1;
	}
	if (orientation == 'S')
	{
		dirx = 0;
		diry = 1;
	}
	if (orientation == 'E')
	{
		dirx = -1;
		diry = 0;
	}
	if (orientation == 'W')
	{
		dirx = 1;
		diry = 0;
	}
}

t_player	player_start(char **map)
{
	int	x;
	int	y;
	int	dirx;
	int	diry;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
				break ;
			x++;
		}
		y++;
	}
	dirx = 0;
	diry = 0;
	player_view(dirx, diry, map[y][x]);
	return ((t_player){x, y, dirx, diry});
}
