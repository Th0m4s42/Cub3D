/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:11 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 21:38:51 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	save_north(t_game *game, char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (incr_to_identifier(line, "NO", &i) == false)
		return (true);
	if (game->visual.north != NULL)
		return (ft_putendl_fd("Multiple NO identifier", 2), false);
	y = i;
	while (line[y] && in_charset(line[y], " \t\n") == false)
		y++;
	game->visual.north = ft_substr(line, i, y - i);
	if (game->visual.north == NULL)
		return (false);
	if (game->visual.north != NULL && ft_strlen(game->visual.north) == 0)
		return (ft_putendl_fd("No path for NO identifier", 2), false);
	return (true);
}

bool	save_south(t_game *game, char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (incr_to_identifier(line, "SO", &i) == false)
		return (true);
	if (game->visual.south != NULL)
		return (ft_putendl_fd("Multiple SO identifier", 2), false);
	y = i;
	while (line[y] && in_charset(line[y], " \t\n") == false)
		y++;
	game->visual.south = ft_substr(line, i, y - i);
	if (game->visual.south == NULL)
		return (false);
	if (game->visual.south != NULL && ft_strlen(game->visual.south) == 0)
		return (ft_putendl_fd("No path for SO identifier", 2), false);
	return (true);
}

bool	save_west(t_game *game, char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (incr_to_identifier(line, "WE", &i) == false)
		return (true);
	if (game->visual.west != NULL)
		return (ft_putendl_fd("Multiple WE identifier", 2), false);
	y = i;
	while (line[y] && in_charset(line[y], " \t\n") == false)
		y++;
	game->visual.west = ft_substr(line, i, y - i);
	if (game->visual.west == NULL)
		return (false);
	if (game->visual.west != NULL && ft_strlen(game->visual.west) == 0)
		return (ft_putendl_fd("No path for WE identifier", 2), false);
	return (true);
}

bool	save_east(t_game *game, char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (incr_to_identifier(line, "EA", &i) == false)
		return (true);
	if (game->visual.east != NULL)
		return (ft_putendl_fd("Multiple EA identifier", 2), false);
	y = i;
	while (line[y] && in_charset(line[y], " \t\n") == false)
		y++;
	game->visual.east = ft_substr(line, i, y - i);
	if (game->visual.east == NULL)
		return (false);
	if (game->visual.east != NULL && ft_strlen(game->visual.east) == 0)
		return (ft_putendl_fd("No path for EA identifier", 2), false);
	return (true);
}
