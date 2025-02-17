/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:11 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/17 17:33:29 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	incr_to_identifier(char *line, char *id, size_t *i)
{
	while (in_charset(line[(*i)], " \t") == true)
		(*i)++;
	if (ft_strncmp(line + (*i), id, 2) != 0)
		return (false);
	(*i) += 2;
	if (in_charset(line[(*i)], " \t") == false)
		return (false);
	while (in_charset(line[(*i)], " \t") == true)
		(*i)++;
	return (true);
}

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
	printf("north = %s\n", game->visual.north);
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
	printf("south = %s\n", game->visual.south);
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
	printf("west = %s\n", game->visual.west);
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
	printf("east = %s\n", game->visual.east);
	return (true);
}
