/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hole.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:23:36 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/19 21:23:52 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	check_up(char **map, int i, int y)
{
	if (i < 0 || y == 0)
		return (false);
	if ((int)ft_strlen(map[i]) < y)
		return (false);
	if (map[i][y - 1] == ' ' || map[i][y] == ' ' || map[i][y + 1] == ' '
		|| map[i][y + 1] == '\n' || map[i][y + 1] == '\0')
		return (false);
	return (true);
}

static bool	check_mid(char **map, int i, int y)
{
	if (y == 0)
		return (false);
	if (map[i][y - 1] == ' ' || map[i][y] == ' ' || map[i][y + 1] == ' '
		|| map[i][y + 1] == '\n' || map[i][y + 1] == '\0')
		return (false);
	return (true);
}

static bool	check_down(char **map, int i, int y)
{
	if (map[i] == NULL)
		return (false);
	if ((int)ft_strlen(map[i]) < y)
		return (false);
	if (map[i][y - 1] == ' ' || map[i][y] == ' ' || map[i][y + 1] == ' '
		|| map[i][y + 1] == '\n' || map[i][y + 1] == '\0')
		return (false);
	return (true);
}

static bool	check_around_ground(char **map, int i, int y)
{
	if (check_up(map, i - 1, y) == false || check_mid(map, i, y) == false
		|| check_down(map, i + 1, y) == false)
		return (false);
	return (true);
}

bool	check_hole(char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if ((map[i][y] == '0' || map[i][y] == 'N' || map[i][y] == 'W'
				|| map[i][y] == 'E' || map[i][y] == 'S')
				&& check_around_ground(map, i, y) == false)
			{
				ft_putendl_fd("Error, found a hole", 2);
				return (false);
			}
		}
	}
	return (true);
}
