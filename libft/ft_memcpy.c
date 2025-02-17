/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:55:28 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 17:53:19 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

/*#include<stdlib.h>
#include<string.h>
int main(void)
{
    int     i;
    int     n = ;
    void    *src;
    void    *dest;

    i = 0;
    src = malloc(10 * sizeof(char));
    dest = malloc(10 * sizeof(char));
    
    while (i < 9)
    {
        *((char *)src + i) = 'w';
        i++;
    }
    *((char *)src + i) = '\0';

    dest = (char *)memcpy(dest, src, n);

    printf("src                 : %s\n", (char *)src);
    printf("dest after memcpy   : %s\n", (char *)dest);

    free(src);
    free(dest);


    i = 0;
    src = malloc(10 * sizeof(char));
    dest = malloc(10 * sizeof(char));
    
    while (i < 9)
    {
        *((char *)src + i) = 'w';
        i++;
    }
    *((char *)src + i) = '\0';

    dest = (char *)ft_memcpy(dest, src, n);

    printf("\n");
    printf("src                 : %s\n", (char *)src);
    printf("dest after ft_memcpy: %s\n", (char *)dest);

    free(src);
    free(dest);


    return (0);
}*/
