/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_visuals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 07:40:55 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/18 07:46:22 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_free_visuals(t_game *game)
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

void	ft_free_game(t_game *game)
{
	ft_free_visuals(game);
}
