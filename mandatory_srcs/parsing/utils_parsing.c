/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:26:08 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/19 21:50:21 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	incr_to_identifier(char *line, char *id, size_t *i)
{
	size_t	len;

	len = ft_strlen (id);
	while (in_charset(line[(*i)], " \t") == true)
		(*i)++;
	if (ft_strncmp(line + (*i), id, len) != 0)
		return (false);
	(*i) += len;
	if (in_charset(line[(*i)], " \t") == false)
		return (false);
	while (in_charset(line[(*i)], " \t") == true)
		(*i)++;
	return (true);
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

bool	all_identifier_set(t_visual visual)
{
	if (!visual.north || !visual.south || !visual.west || !visual.east)
		return (false);
	if (visual.floor_r == -1 || visual.floor_g == -1 || visual.floor_b == -1)
		return (false);
	if (visual.cell_r == -1 || visual.cell_g == -1 || visual.cell_b == -1)
		return (false);
	return (true);
}

bool	empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (in_charset(*(line + i), "\t\v\n\f\r"))
		i++;
	if (*(line + i) == '\0')
		return (true);
	return (false);
}



int	cub3d_atoi(char *str)
{
	size_t	i;
	int		value;
	int		count;

	i = -1;
	value = 0;
	count = 0;
	while (in_charset(str[++i], "0123456789") == true)
	{
		if (count > 3)
		{
			value = -1;
			break ;
		}
		count++;
		value = (value * 10) + (str[i] - '0');
	}
	if (value > 255)
		return (-1);
	return (value);
}
