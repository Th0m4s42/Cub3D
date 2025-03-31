/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:13:12 by ckenaip           #+#    #+#             */
/*   Updated: 2025/03/31 04:19:48 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_function_array(t_array (*funct_array)[7])
{
	(*funct_array)[0] = save_north;
	(*funct_array)[1] = save_south;
	(*funct_array)[2] = save_west;
	(*funct_array)[3] = save_east;
	(*funct_array)[4] = save_floor;
	(*funct_array)[5] = save_celling;
	(*funct_array)[6] = NULL;
}

static bool	save_visual(t_game *game, char **line, int fd)
{
	t_array	checker_identifier[7];
	size_t	i;
	size_t	y;

	i = -1;
	init_function_array(&checker_identifier);
	while (*line)
	{
		y = 0;
		while (in_charset((*line)[y], " \t\v\f\r\n") == true)
			y++;
		if (in_charset((*line)[y], "01") && all_identifier_set(game->visual))
			break ;
		if (check_id(*line, y) == false)
			return (free(*line), false);
		while (checker_identifier[++i])
		{
			if (checker_identifier[i](game, *line) == false)
				return (free(*line), false);
		}
		i = -1;
		free(*line);
		*line = get_next_line(fd);
	}
	return (true);
}

static bool	check_config_file(t_game *game, int fd)
{
	char		*line;

	line = get_next_line(fd);
	if (save_visual(game, &line, fd) == false)
		return (false);
	while (line)
	{
		ft_realloc_cub3d(&game->map, line);
		if (game->map == NULL)
			return (ft_putendl_fd("Error malloc", 2), false);
		line = get_next_line(fd);
	}
	if (game->map == NULL || game->map[0] == NULL)
		return (ft_putendl_fd("no Map in files", 2), false);
	return (true);
}

bool	ft_parsing(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror(path), false);
	if (check_config_file(game, fd) == false)
	{
		get_next_line(-1);
		close(fd);
		return (false);
	}
	if (check_hole(game->map) == false || checker_map(game->map) == false)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
