/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:03:04 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 21:52:50 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_visual
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	bool	floor;
	int		floor_r;
	int		floor_g;
	int		floor_b;

	bool	celling;
	int		cell_r;
	int		cell_g;
	int		cell_b;
}	t_visual;

typedef struct s_game
{
	t_visual	visual;
	char		**map;
	//player
	//mlx
	//ptr
}	t_game;

typedef bool	(*t_array)(t_game *game, char *line);

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

/*******************************PARSING****************************************/


/*	check_args.c	*/
bool	check_args(int ac, char **av, char **envp);

/*	ft_check_hole.c	*/
bool	check_hole(char **map);

/*	ft_checker_map.c	*/
bool	checker_map(char **map);

/*	ft_parsing.c	*/
bool	ft_parsing(t_game *game, char *path);

/*	save_color_background.c	*/
bool	save_celling(t_game *game, char *line);
bool	save_floor(t_game *game, char *line);

/*	save_path_textures.c	*/
bool	save_north(t_game *game, char *line);
bool	save_south(t_game *game, char *line);
bool	save_west(t_game *game, char *line);
bool	save_east(t_game *game, char *line);

/*	utils_check_id.c	*/
bool	check_id(char *line, size_t i);

/*	utils_parsing.c	*/
bool	incr_to_identifier(char *line, char *id, size_t *i);
bool	in_charset(char c, char *charset);
bool	all_identifier_set(t_visual visual);
bool	empty_line(char *line);
int		cub3d_atoi(char *str);

/*	utils_realloc	*/
void	ft_realloc_cub3d(char ***src, char *line);

/*	BONUS non normé*/
void	print_visual_value(t_visual visual, char **map);// in check id file

/*******************************EXIT*******************************************/

void	ft_free_game(t_game *game);

#endif