/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:11 by ckenaip           #+#    #+#             */
/*   Updated: 2025/03/06 20:11:02 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	get_texture(t_game *game, t_tex *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path,
			&texture->width, &texture->height);
	if (texture->img == NULL)
		return ;
	texture->addr = mlx_get_data_addr(&texture->img, &texture->bpp,
		&texture->size_line, &texture->endian);
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
	while (line[y] && in_charset(line[y], " \t\n") == true)
		y++;
	if (line[y])
		return (ft_putendl_fd("Error: invalid syntax NO Identifier", 2), false);
	if (game->visual.north != NULL && ft_strlen(game->visual.north) == 0)
		return (ft_putendl_fd("No path for NO identifier", 2), false);
	get_texture(game, &game->north, game->visual.north);
	if (game->north.img == NULL)
		return (ft_putendl_fd("Error north xpm file", 2), false);
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
	while (line[y] && in_charset(line[y], " \t\n") == true)
		y++;
	if (line[y])
		return (ft_putendl_fd("Error: invalid syntax SO Identifier", 2), false);
	if (game->visual.south != NULL && ft_strlen(game->visual.south) == 0)
		return (ft_putendl_fd("No path for SO identifier", 2), false);
	get_texture(game, &game->south, game->visual.south);
	if (game->south.img == NULL)
		return (ft_putendl_fd("Error south xpm file", 2), false);
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
	while (line[y] && in_charset(line[y], " \t\n") == true)
		y++;
	if (line[y])
		return (ft_putendl_fd("Error: invalid syntax WE Identifier", 2), false);
	if (game->visual.west != NULL && ft_strlen(game->visual.west) == 0)
		return (ft_putendl_fd("No path for WE identifier", 2), false);
	get_texture(game, &game->west, game->visual.west);
	if (game->west.img == NULL)
		return (ft_putendl_fd("Error west xpm file", 2), false);
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
	while (line[y] && in_charset(line[y], " \t\n") == true)
		y++;
	if (line[y])
		return (ft_putendl_fd("Error: invalid syntax EA Identifier", 2), false);
	if (game->visual.east != NULL && ft_strlen(game->visual.east) == 0)
		return (ft_putendl_fd("No path for EA identifier", 2), false);
	get_texture(game, &game->east, game->visual.east);
	if (game->east.img == NULL)
		return (ft_putendl_fd("Error east xpm file", 2), false);
	return (true);
}
