/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:18:38 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/17 17:19:26 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* PARAMETER s1: The string to be trimmed.

SET: The reference set of characters to trim.

RETURN VALUE The trimmed string.

NULL if the allocation fails.

EXTERNAL FUNCT. malloc

DESCRIPTION Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.*/

static size_t	checkif(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_fullfil(char const *s1, char *trim, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start + i < end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1)
		return (0);
	if (ft_strlen(set) == 0 || !set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (checkif(s1[start], (char *)set) && start != end)
		start++;
	while (checkif(s1[end - 1], (char *)set) && (end - 1) >= start)
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!trim)
		return (NULL);
	return (ft_fullfil(s1, trim, start, end));
}

/*int   main(void)
{
        char    *test;

        test = ft_strtrim("abcdba", "acb");
        printf("%s\n", test);
        free(test);
        return (0);
}*/
