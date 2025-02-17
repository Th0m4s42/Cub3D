/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:44:04 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:30:16 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	td;
	size_t	ts;

	ts = ft_strlen(src);
	if (dstsize == 0)
		return (ts);
	i = 0;
	td = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= td)
		return (dstsize + ts);
	while (src[i] && (td + i) < dstsize - 1)
	{
		dst[td + i] = src[i];
		i++;
	}
	dst[td + i] = '\0';
	return (td + ts);
}
