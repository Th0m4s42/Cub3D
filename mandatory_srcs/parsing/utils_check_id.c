/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:35:24 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/24 07:38:50 by thbasse          ###   ########.fr       */
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

void	print_visual_value(t_visual visual, char **map)
{
	printf("Path :\n");
	printf("\tNO -> %s\n", visual.north);
	printf("\tWE -> %s\n", visual.west);
	printf("\tEA -> %s\n", visual.east);
	printf("\tSO -> %s\n", visual.south);
	printf("Floor value :\n");
	printf("\tR = %d, G = %d, B = %d\n",
		visual.floor_r, visual.floor_g, visual.floor_b);
	printf("Celling value :\n");
	printf("\tR = %d, G = %d, B = %d\n",
		visual.cell_r, visual.cell_g, visual.cell_b);
	if (map)
	{
		for (int i = 0; map[i]; i++) {
			printf("%s", map[i]);
		};
		printf("\n");
	}
	else
		printf("No map\n");
}
