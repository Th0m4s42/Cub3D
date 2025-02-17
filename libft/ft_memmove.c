/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:36:24 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 17:55:17 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	target;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			target = ((char *)src)[i];
			((char *)dest)[i] = target;
			i++;
		}
		return (dest);
	}
	while (n >= 1)
	{
		target = ((char *)src)[n - 1];
		((char *)dest)[n - 1] = target;
		n--;
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	// char *src = malloc(sizeof(char) * 9);
	char src[9];
	src[0] = '0';
	src[1] = '1';
	src[2] = '2';
	src[3] = '3';
	src[4] = '4';
	src[5] = '5';
	src[6] = '6';
	src[7] = '7';
	src[8] = '\0';

	printf("original src : %s\n", src);

	memmove((void *)src+2, (void *)src, 5);
	printf("memmove      : %s\n", src);

	src[0] = '0';
	src[1] = '1';
	src[2] = '2';
	src[3] = '3';
	src[4] = '4';
	src[5] = '5';
	src[6] = '6';
	src[7] = '7';
	src[8] = '\0';

	ft_memmove((void *)src+2, (void *)src, 5);
	printf("ft_memmove   : %s\n", src);


	return (0);
}*/
