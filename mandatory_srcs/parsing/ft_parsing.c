/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:13:12 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/17 17:38:49 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_function_array(t_array (*funct_array)[7])
{
	(*funct_array)[0] = save_north;
	(*funct_array)[1] = save_south;
	(*funct_array)[2] = save_west;
	(*funct_array)[3] = save_east;
	(*funct_array)[4] = NULL;
	(*funct_array)[5] = NULL;
	(*funct_array)[6] = NULL;
}

static bool	check_config_file(t_game *game, int fd)
{
	char		*line;
	int			i;
	size_t		y;
	t_array		checker_identifier[7];

	init_function_array(&checker_identifier);
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		//aller directement a lidentifier ici!,
		// check si line vide ou si wrong identifier
		y = 0;
		while (in_charset(line[y], " \t\n") == true)
			y++;
		if (check_id(line, y) == false)
			return (false);//penser a free
		while (checker_identifier[++i])
		{
			if (checker_identifier[i](game, line) == false)
				return (false);
		}
		i = -1;
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
