/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:02:00 by ckenaip           #+#    #+#             */
/*   Updated: 2025/03/06 21:46:48 by curry-san        ###   ########.fr       */
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

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_putstr_fd("Error\nmlx_init failed\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (game->win == NULL)
	{
		ft_putstr_fd("Error\nmlx_new_window failed\n", 2);
		ft_free_game(game);
		exit(1);
	}
	game->key_img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->map_img.img = mlx_new_image(game->mlx, WIDTH_MAP, HEIGHT_MAP);
	if (game->key_img.img == NULL)
	{
		ft_putstr_fd("Error\nmlx_new_image failed\n", 2);
		exit(1);
	}
	game->key_img.addr = mlx_get_data_addr(game->key_img.img, &game->key_img.bpp, &game->key_img.size_line, &game->key_img.endian);
	game->map_img.addr = mlx_get_data_addr(game->map_img.img, &game->map_img.bpp, &game->map_img.size_line, &game->map_img.endian);
	mlx_put_image_to_window(game->mlx, game->win, game->key_img.img, 0, 0);
}

static void	init_textures(t_game *game)
{
	game->north.img = NULL;
	game->south.img = NULL;
	game->west.img = NULL;
	game->east.img = NULL;
}

static void	init_game(t_game *game)
{
	game->visual.north = NULL;
	game->visual.south = NULL;
	game->visual.west = NULL;
	game->visual.east = NULL;
	game->visual.floor = false;
	game->visual.floor_r = -1;
	game->visual.floor_g = -1;
	game->visual.floor_b = -1;
	game->visual.celling = false;
	game->visual.cell_r = -1;
	game->visual.cell_g = -1;
	game->visual.cell_b = -1;
	game->map = NULL;
	init_textures(game);
	init_mlx(game);
}

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	if (check_args(ac, ++av, envp) == false)
		return (1);
	init_game(&game);
	if (ft_parsing(&game, *av) == false)
		return (ft_free_game(&game), 0);
	// print_visual_value(game.visual, game.map);
	init_player(&game);
	init_key_event(&game);
	mlx_loop_hook(game.mlx, draw_wall, &game);
	mlx_loop(game.mlx);
	ft_free_game(&game);
	return (0);
}
