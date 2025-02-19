/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:41:07 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 11:42:30 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// static bool	incr_to_identifier(char *line, char *id, size_t *i)
// {
// 	while (in_charset(line[(*i)], " \t") == true)
// 		(*i)++;
// 	if (ft_strncmp(line + (*i), id, 1) != 0)
// 		return (false);
// 	(*i) += 1;
// 	if (in_charset(line[(*i)], " \t") == false)
// 		return (false);
// 	while (in_charset(line[(*i)], " \t") == true)
// 		(*i)++;
// 	return (true);
// }

bool	check_syntaxe(char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (y < 3)
	{
		if (y < 2 && (line[i] <= '0' || line[i] >= '9'))//first check
			return (false);
		while (line[i] <= '9' && line[i] >= '0')
			i++;
		while (in_charset(line[i], "\t\v\n\f\r "))
			i++;
		if (line[i++] != ',')
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
	(void)game;

	i = 0;
	if (incr_to_identifier(line, "F", &i) == false)
		return (true);
	if (game->visual.floor == true)
		return (ft_putendl_fd("Multiple F identifier", 2), false);
	game->visual.floor = true;
	if (check_syntaxe((line + i)) == false)
		return (false);
	return (true);
}

bool	save_celling(t_game *game, char *line)
{
	size_t	i;
	(void)game;

	i = 0;
	if (incr_to_identifier(line, "C", &i) == false)
		return (true);
	return (true);
}
