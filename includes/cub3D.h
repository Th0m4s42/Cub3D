/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:03:04 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 11:36:40 by curry-san        ###   ########.fr       */
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

bool	check_args(int ac, char **av, char **envp);
bool	ft_parsing(t_game *game, char *path);
bool	save_north(t_game *game, char *line);
bool	save_south(t_game *game, char *line);
bool	save_west(t_game *game, char *line);
bool	save_east(t_game *game, char *line);
bool	save_celling(t_game *game, char *line);
bool	save_floor(t_game *game, char *line);
bool	in_charset(char c, char *charset);
bool	incr_to_identifier(char *line, char *id, size_t *i);
bool	check_id(char *line, size_t i);
bool	all_identifier_set(t_visual visual);


/*******************************EXIT*******************************************/

void	ft_free_visuals(t_game *game);
void	ft_free_game(t_game *game);

#endif