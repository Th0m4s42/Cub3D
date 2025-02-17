/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:53:33 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:38:15 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	ft_nstrlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(0);
		return (mem);
	}
	if ((nmemb * size) < size || (nmemb * size) < nmemb)
		return (0);
	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	return (mem);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src || !dest || n == 0)
		return (NULL);
	while (i < n && ((char *)src)[i])
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	((char *)dest)[i] = '\0';
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	new = ft_calloc(size, sizeof(char));
	if (new == 0)
		return (0);
	new = ft_memcpy(new, ptr, size);
	if (ptr)
		free(ptr);
	return (new);
}
