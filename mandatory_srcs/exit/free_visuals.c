/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_visuals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 07:40:55 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/21 14:24:03 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	ft_free_map(char **map)
{
	size_t	i;

	if (map == NULL)
		return ;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

static void	ft_free_visual(t_visual *visual)
{
	free(visual->north);
	free(visual->south);
	free(visual->west);
	free(visual->east);
}

void	ft_free_game(t_game *game)
{
	if (game->key_img.img != NULL)
		mlx_destroy_image(game->mlx, game->key_img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_visual(&game->visual);
	ft_free_map(game->map);
}
