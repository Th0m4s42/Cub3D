/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:30:23 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/19 21:30:46 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	check_charactere(char c, int *occurence)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
	{
		*occurence = *occurence + 1;
		return (true);
	}
	else if (c == ' ' || c == '\n' || c == '1' || c == '0')
		return (true);
	ft_putendl_fd("Error, invalid charatere mixed in", 2);
	return (false);
}

static bool	check_characteres(char **map)
{
	int	occurence;
	int	i;
	int	y;

	occurence = 0;
	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (check_charactere(map[i][y], &occurence) == false)
				return (false);
		}
	}
	if (occurence == 0 || occurence > 1)
	{
		ft_putendl_fd("Error, invalid number of player.", 2);
		return (false);
	}
	return (true);
}

static bool	check_empty_line(char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] != ' ')
				break ;
		}
		if (map[i][y] == '\n' || map[i][y] == '\0')
		{
			ft_putendl_fd("Error, empty line found", 2);
			return (false);
		}
	}
	return (true);
}

bool	checker_map(char **map)
{
	if (check_empty_line(map) == false
		|| check_characteres(map) == false
		|| check_hole(map) == false)
		return (false);
	return (true);
}
