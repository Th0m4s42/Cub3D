/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/03/27 23:09:06 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_tex	get_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->raydiry > 0)
			return (game->north);
		return (game->south);
	}
	else
	{
		if (ray->raydirx > 0)
			return (game->west);
		return (game->east);
	}
}



void	get_color(t_game *game, t_ray *ray)
{
	game->color = 0xff0000;
	
	//calculate value of wallX
	if (ray->side == 0)
		game->wall_x = game->player.y + ray->perpwalldist * ray->raydiry;
	else
		game->wall_x = game->player.x + ray->perpwalldist * ray->raydirx;
	game->wall_x -= (int)(game->wall_x);
	//x coordinate on the texture
	game->tex = get_texture(game, ray);
	game->tex_x = (int)(game->wall_x * (float)game->tex.width);
	if ((ray->side == 0 && ray->raydirx > 0) || (ray->side == 1 && ray->raydiry < 0))
		game->tex_x = game->tex.width - game->tex_x - 1;
	// How much to increase the texture coordinate per screen pixel
	game->step = 1.0 * game->tex.height / game->line_height;
	// Starting texture coordinate
	game->tex_pos = (game->draw_start - HEIGHT / 2 + game->line_height / 2) * game->step;
	game->tex_y = (int)game->tex_pos & (game->tex.height - 1);
	game->tex_pos += game->step;
	// game->color = game->south.addr[0];
}

void	draw_line(t_game *game, int start, int end, int x)
{
	int	i;

	i = -1;
	while (++i < start)
	{
		put_pixel(&game->key_img, x, i, rgb_to_int(game->visual.cell_r, \
		game->visual.cell_g, game->visual.cell_b));
	}
	while (start < end)
	{
		get_color(game, &game->ray);
		put_pixel(&game->key_img, x, start, game->color);
		start++;
	}
	while (start < HEIGHT)
	{
		put_pixel(&game->key_img, x, start, rgb_to_int(game->visual.floor_r, \
		game->visual.floor_g, game->visual.floor_b));
		start++;
	}
}




// void	get_color(t_game *game, t_ray *ray)
// {
// 	if (ray->side == 1)
// 	{
// 		game->color = 0xFF0000; // Red for y-side walls south
// 		if (ray->raydiry > 0)
// 			game->color = 0x0000ff;//north
// 	}
// 	else if (ray->side == 0)
// 	{
// 		game->color = 0x00FF00; // Green for x-side walls
// 		if (ray->raydirx > 0)
// 			game->color = 0xff00ff;	
// 	}
// }

int	draw_wall(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		game->ray = init_ray(game, x);
		dda(&game->ray, game);
		game->line_height = (int)(HEIGHT / game->ray.perpwalldist);
		game->draw_start = -game->line_height / 2 + HEIGHT / 2;
		if (game->draw_start < 0)
			game->draw_start = 0;
		game->draw_end = game->line_height / 2 + HEIGHT / 2;
		if (game->draw_end >= HEIGHT)
			game->draw_end = HEIGHT - 1;
		// get_color(game, &game->ray);
		draw_line(game, game->draw_start, game->draw_end, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->key_img.img, 0, 0);
	action_key(game);
	draw_map(game);
	return (0);
}
