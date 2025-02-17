/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:35:24 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/17 17:37:43 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	check_id_texture(char *c, size_t i)
{
	if ((!ft_strncmp(c, "NO", 2) || !ft_strncmp(c, "SO", 2)
			|| !ft_strncmp(c, "WE", 2) || !ft_strncmp(c, "EA", 2))
		&& in_charset(c[i + 2], " \t"))
		return (true);
	return (false);
}

static bool	check_id_background(char *c, size_t i)
{
	if ((ft_strncmp(c, "F", 1) == 0 || ft_strncmp(c, "C", 1) == 0)
		&& in_charset(c[i + 1], " \t"))
		return (true);
	return (false);
}

bool	check_id(char *line, size_t i)
{
	if (line[i] == '\0')
		return (true);
	if (check_id_texture(line, i) || check_id_background(line, i))
		return (true);
	return (ft_putendl_fd("Wrong identifier", 2), false);
}

bool	in_charset(char c, char *charset)
{
	size_t	i;

	if (charset == NULL)
		return (false);
	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (true);
	}
	return (false);
}
