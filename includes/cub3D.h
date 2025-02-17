/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:03:04 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/17 15:03:30 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_visual
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		floor_r;
	int		floor_g;
	int		floor_b;

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

/*  PARSING */
bool	check_args(int ac, char **av, char **envp);

#endif