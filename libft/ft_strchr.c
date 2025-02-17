/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:58:19 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/10 17:41:26 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		while (s[i])
			i++;
		return (&*((char *)s + i));
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

/*#include<string.h>
#include<stdio.h>
int	main(void)
{
	char	*test1 = "patatedefer\0banane";
	char	*test2 = "patatedefer";

	printf("test1\n");
	if (ft_strchr(test1, 0) == strchr(test1, 0))
		printf("OK\n");
	else
	{
		printf("KO\n");
		printf("ft = %s, original = %s\n", ft_strchr(test1, 97),
strchr(test1, 97));
	}
        printf("test2\n");
        if (ft_strchr(test2, 113) == strchr(test2, 113))
                printf("OK\n");
        else
        {
                printf("KO\n");
                printf("ft = %s, original = %s\n", ft_strchr(test2, 113),
strchr(test2, 113));
        }
	return (0);
}*/
