/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:02:00 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/18 07:36:13 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/*		EXTERNAL FUNCTS. :

	• open, close, read, write,
	printf, malloc, free, perror,
	strerror, exit, gettimeofday

	• All functions of the math
	library (-lm man man 3 math)

	• All functions of the MinilibX
*/

/*
	PARSING:

	int rgb_to_int(double r, double g, double b)
	{
    	int color = 0;
    	color |= (int)(b * 255);
    	color |= (int)(g * 255) << 8;
    	color |= (int)(r * 255) << 16;
    	return (color);
	}

*/

void	init_game(t_game *game)
{
	game->visual.north = NULL;
	game->visual.south = NULL;
	game->visual.west = NULL;
	game->visual.east = NULL;
	game->visual.floor_r = -1;
	game->visual.floor_g = -1;
	game->visual.floor_b = -1;
	game->visual.cell_r = -1;
	game->visual.cell_g = -1;
	game->visual.cell_b = -1;
	game->map = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	if (check_args(ac, ++av, envp) == false)
		return (1);
	init_game(&game);
	ft_parsing(&game, *av);
	ft_free_game(&game);
	return (0);
}
