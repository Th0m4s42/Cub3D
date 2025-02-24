/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:29:38 by thbasse           #+#    #+#             */
/*   Updated: 2025/02/24 10:51:54 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel(t_game *game, int x, int y, int color)
{
	int	index;

	index = y * game->key_img.size_line + x * game->key_img.bpp / 8;
	game->key_img.addr[index] = color & 0xFF;
	game->key_img.addr[index + 1] = (color >> 8) & 0xFF;
	game->key_img.addr[index + 2] = (color >> 16) & 0xFF;
}

void	draw_line(t_game *game, int start, int end, int x, int color)
{
	while (start < end)
	{
		put_pixel(game, x, start, color);
		start++;
	}
}
