/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:51:25 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/10 17:39:38 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return (((void *)s + i));
		i++;
	}
	return (0);
}

/*#include<string.h>
int	main(void)
{
	void	*blop = "abcdefghijklmnopqrstuvwxyz";
	int	c = 0;
	size_t	n = 36;

	printf("test:\n");
	if (ft_memchr(blop, c, n) == memchr(blop, c, n))
		printf("feels good to be good\n");
	else
	{	
		printf("SADNESS my boy, looks for error:\n");
		printf("the real: %s\nthe ft  : %s\n", memchr(blop, c, n),
ft_memchr(blop, c, n));
	}
	return (0);
}*/
