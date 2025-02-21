/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_visuals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 07:40:55 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/21 12:29:06 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>


static void	ft_free_visuals(t_game *game)
{
	if (game->visual.north)
		free(game->visual.north);
	if (game->visual.south)
		free(game->visual.south);
	if (game->visual.west)
		free(game->visual.west);
	if (game->visual.east)
		free(game->visual.east);
}

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

void	ft_free_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game->map);
	// ft_free_visuals(game);
}
