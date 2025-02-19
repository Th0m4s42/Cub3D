/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curry-san <curry-san@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:12:55 by curry-san         #+#    #+#             */
/*   Updated: 2025/02/19 21:13:41 by curry-san        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	ft_free_tab(char ***src)
{
	size_t	i;

	i = -1;
	while ((*src)[++i])
		free((*src)[i]);
	free(*src);
	*src = NULL;
}

static size_t	ft_strlen_tab(char **src)
{
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

static void	ft_init_map(char ***src, char *line)
{
	*src = malloc(sizeof(char *) * 2);
	if (*src == NULL)
		return ;
	(*src)[0] = line;
	(*src)[1] = NULL;
}

void	ft_realloc_cub3d(char ***src, char *line)
{
	size_t	len;
	size_t	i;
	char	**new;

	if (*src == NULL)
	{
		ft_init_map(src, line);
		return ;
	}
	len = ft_strlen_tab(*src);
	new = malloc(sizeof(char *) * (len + 2));
	if (new == NULL)
	{
		free(line);
		ft_free_tab(src);
		*src = NULL;
		return ;
	}
	i = -1;
	while (++i < len)
		new[i] = (*src)[i];
	new[i] = line;
	new[i + 1] = NULL;
	free(*src);
	*src = new;
}
