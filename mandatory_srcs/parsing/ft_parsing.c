/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:13:12 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 13:52:14 by curry-san        ###   ########.fr       */
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
		while (in_charset(*(line[y]), " \t\v\f\r\n") == true)
			y++;
		if (in_charset(*(line[y]), "01") && all_identifier_set(game->visual))
			break ;
		if (check_id(*line, y) == false)
			return (free(*line), false);//penser a free
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
	// int			i;
	// size_t		y;
	// t_array		checker_identifier[7];

	// init_function_array(&checker_identifier);
	// i = -1;
	line = get_next_line(fd);
	if (save_visual(game, &line, fd) == false)
		return (false);
	// while (line)
	// {
	// 	y = 0;
	// 	while (in_charset(line[y], " \t\v\f\r\n") == true)
	// 		y++;
	// 	if (in_charset(line[y], "01") && all_identifier_set(game->visual))
	// 		break ;
	// 	if (check_id(line, y) == false)
	// 		return (free(line), false);//penser a free
	// 	while (checker_identifier[++i])
	// 	{
	// 		if (checker_identifier[i](game, line) == false)
	// 			return (free(line), false);
	// 	}
	// 	i = -1;
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	printf("trying to save map\n");
	while (line)
	{
		//SAVE MAP;
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

bool	ft_parsing(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror(path), false);
	return (check_config_file(game, fd));
}
