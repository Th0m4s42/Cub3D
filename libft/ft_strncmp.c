/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:18:21 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 17:59:26 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char)s1[i] || (unsigned char)s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include<string.h>
int     main(void)
{
        char    *test1 = "patatedfweqf";
        char    *test2 = "patatedefer   ";

        printf("test1\n");
        if (ft_strncmp(test1, test2, 5) == strncmp(test1, test2, 5))
                printf("OK\n");
        else
        {
                printf("KO\n");
                printf("ft = %i, original = %i\n", ft_strncmp(test1, test2, 5),
strncmp(test1, test2, 5));
        }
        return (0);
}*/
