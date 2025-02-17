/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:17:09 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/17 08:33:20 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (1);
	}
	if (parse_cub(argv[1], &game))
	{
		ft_putstr_fd("Error\nParsing failed\n", 2);
		return (1);
	}
	if (init_game(&game))
	{
		ft_putstr_fd("Error\nGame initialization failed\n", 2);
		return (1);
	}
	play(&game);
	return (0);
}
