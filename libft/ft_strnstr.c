/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:23:01 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:15:49 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lenlittle;

	if (!len && !big)
		return (0);
	lenlittle = ft_strlen(little);
	i = 0;
	if (!little || ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, lenlittle) == 0
				&& len - i >= lenlittle)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

/*#include<bsd/string.h>
int	main(void)
{
	//char haystack[30] = "aaabcabcdiii";
	//char test[5] = "abcd";
	//char needle[10] = "aabc";
	char * empty = (char*)"";

	if (ft_strnstr(empty, "", -1) == empty)
		printf("good to be good");
	else
	{
		printf("try again! the fake : %s\n", ft_strnstr(empty, "", -1));
		printf("           the real : %s", strnstr(empty, "", -1));
	}

	//printf("\n%s", test);
	return (0);
}*/
