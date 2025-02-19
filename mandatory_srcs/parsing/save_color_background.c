/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:07 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 21:37:40 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	save_floor_value(t_game *game, char *line, size_t y, char id)
{
	if (id != 'F')
		return (true);
	if (y == 0)
		game->visual.floor_r = cub3d_atoi(line);
	else if (y == 1)
		game->visual.floor_g = cub3d_atoi(line);
	else
	{
		game->visual.floor_b = cub3d_atoi(line);
		if (game->visual.floor_r == -1 || game->visual.floor_g == -1
			|| game->visual.floor_b == -1)
			return (false);
	}
	return (true);
}

static bool	save_celling_value(t_game *game, char *line, size_t y, char id)
{
	if (id != 'C')
		return (true);
	if (y == 0)
		game->visual.cell_r = ft_atoi(line);
	else if (y == 1)
		game->visual.cell_g = ft_atoi(line);
	else
	{
		game->visual.cell_b = ft_atoi(line);
		if (game->visual.cell_r == -1 || game->visual.cell_g == -1
			|| game->visual.cell_b == -1)
			return (false);
	}
	return (true);
}

static bool	check_syntaxe(t_game *game, char *line, char id)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (y < 3)
	{
		if (y < 2 && (line[i] <= '0' || line[i] >= '9')) //first check
			return (false);
		if (save_floor_value(game, (line + i), y, id) == false
			|| save_celling_value(game, (line + i), y, id) == false)
			return (false);
		while (line[i] <= '9' && line[i] >= '0')
			i++;
		while (in_charset(line[i], "\t\v\n\f\r "))
			i++;
		if (y < 2 && line[i++] != ',')
			return (false);
		while (in_charset(line[i], "\t\v\n\f\r "))
			i++;
		if (y == 2 && line[i] != '\0')
			return (false);
		y++;
	}
	return (true);
}

bool	save_floor(t_game *game, char *line)
{
	size_t	i;

	i = 0;
	if (incr_to_identifier(line, "F", &i) == false)
		return (true);
	if (game->visual.floor == true)
		return (ft_putendl_fd("Multiple F identifier", 2), false);
	game->visual.floor = true;
	if (check_syntaxe(game, (line + i), 'F') == false)
		return (ft_putendl_fd("Error syntaxe F identifier", 2), false);
	return (true);
}

bool	save_celling(t_game *game, char *line)
{
	size_t	i;

	i = 0;
	if (incr_to_identifier(line, "C", &i) == false)
		return (true);
	if (game->visual.celling == true)
		return (ft_putendl_fd("Multiple C identifier", 2), false);
	game->visual.celling = true;
	if (check_syntaxe(game, (line + i), 'C') == false)
		return (ft_putendl_fd("Error syntaxe C identifier", 2), false);
	return (true);
}
