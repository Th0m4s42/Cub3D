/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:32:17 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:34:00 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	y;
	char	*join;

	if (!s1 || !s2)
		return (0);
	i = 0;
	y = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (0);
	while (s1[i])
	{
		join[i + y] = s1[i];
		i++;
	}
	while (s2[y])
	{
		join[i + y] = s2[y];
		y++;
	}
	join[i + y] = '\0';
	return (join);
}

/*int	main(void)
{
	char	*test;

	test = ft_strjoin("tripouille", "42");
	printf("%s\n", test);
	free(test);
	return (0);
}*/
