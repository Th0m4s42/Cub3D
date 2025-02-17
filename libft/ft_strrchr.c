/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:06:04 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/10 17:43:22 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	pos = 0;
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
			pos = i;
		i++;
	}
	if (pos == 0 && s[0] != (char)c)
		return (0);
	return (&*(char *)s + pos);
}

/*#include<string.h>
#include<stdio.h>
int     main(void)
{
char    *test1 = "patatedefer";
char    *test2 = "qfjowrnvsoiqoqoihqoii";

printf("test1\n");
if (ft_strrchr(test1, 0) == strrchr(test1, 0))
printf("OK\n");
else
{
printf("KO\n");
printf("ft = %s, original = %s\n", ft_strrchr(test1, 97),
strrchr(test1, 97));
}
printf("test2\n");
if (ft_strrchr(test2, 113) == strrchr(test2, 113))
printf("OK\n");
else
{
printf("KO\n");
printf("ft = %s, original = %s\n", ft_strrchr(test2, 113),
strrchr(test2, 113));
}
return (0);
}*/
