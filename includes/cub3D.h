/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:03:04 by ckenaip           #+#    #+#             */
/*   Updated: 2025/03/25 20:20:48 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>

////////////////////////////////////////////////////////////////////////////////
//								DEFINES										  //
////////////////////////////////////////////////////////////////////////////////

# define WIDTH 1080
# define HEIGHT 520
# define WIDTH_MAP 150
# define HEIGHT_MAP 80
# define BLOCK_SIZE 64
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.05
# define PI 3.14159265359

//	KEY EVENT	//
# define ESC_KEY 65307
# define CAMERA_LEFT 65361
# define CAMERA_RIGHT 65363
# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100
# define KEY_P 112
# define KEY_M 109

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_player
{
	float	x;
	float	y;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;

	bool	key_up;
	bool	key_down;
	bool	key_right;
	bool	key_left;

	bool	camera_left;
	bool	camera_right;

	bool	key_map;
}	t_player;

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

typedef struct	s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr;
	void	*img;
}	t_img;

typedef struct	s_tex
{
	int		width;
	int		height;
	
	int		bpp;
	int		size_line;
	int		endian;
	
	char	*addr;
	void	*img;
}	t_tex;

typedef struct s_ray
{
	float	camerax;		// Position X sur le plan caméra (-1 à 1)
	float	raydirx;		// Direction du rayon en X
	float	raydiry;		// Direction du rayon en Y

	int		mapx;			// Position X actuelle sur la grille
	int		mapy;			// Position Y actuelle sur la grille

	float	sidedistx;		// Distance parcourue dans X avant de rencontrer une ligne de grille
	float	sidedisty;		// Distance parcourue dans Y avant de rencontrer une ligne de grille

	float	deltadistx;		// Distance entre deux lignes de grille en X
	float	deltadisty;		// Distance entre deux lignes de grille en Y
	float	perpwalldist;	// Distance perpendiculaire à la caméra (corrige la distorsion)

	int		stepx;			// Direction du pas en X (+1 ou -1)
	int		stepy;			// Direction du pas en Y (+1 ou -1)
	int		hit;			// 1 si un mur est touché, sinon 0
	int		side; 			// 0 = mur vertical, 1 = mur horizontal
}	t_ray;

typedef struct s_game
{
	t_visual	visual;
	t_tex		north;
	t_tex		south;
	t_tex		west;
	t_tex		east;
	char		**map;
	t_player	player;
	t_img		key_img;
	t_img		map_img;
	void		*mlx;
	void		*win;
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

/*	BONUS non normé	*/
void	print_visual_value(t_visual visual, char **map);// in check id file

/*******************************RAYCASTING*************************************/

t_ray	init_ray(t_game *game, int x);
void	dda(t_ray *ray, t_game *game);

/*******************************GAME*******************************************/

/*	player.c	*/
void		init_player(t_game *game);
t_player	player_start(char **map);
void		put_pixel(t_img *img, int x, int y, int color);
void		draw_line(t_game *game, int start, int end, int x, int color);
int			draw_wall(t_game *game);
void		draw_map(t_game *game);
void	draw_texture(t_game *game, t_ray *ray);

/*******************************KEY EVENT**************************************/

void	init_key_event(t_game *game);
int		cross_event(t_game *game);

/********************************MOVEMENTS*************************************/

void	w_key(t_game *game);
void	s_key(t_game *game);
void	a_key(t_game *game);
void	d_key(t_game *game);

/********************************ROTATION**************************************/

void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

/*******************************EXIT*******************************************/

void	ft_free_game(t_game *game);

/*		POUBELLE	*/
size_t	ft_tablen(char **tab);

#endif