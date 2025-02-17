/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:59:45 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:48:54 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	how_much_split(char *tosplit, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (tosplit[i] == c && tosplit[i])
		i++;
	while (tosplit[i])
	{
		while (tosplit[i] != c && tosplit[i])
			i++;
		while (tosplit[i] == c && tosplit[i])
			i++;
		count++;
	}
	return (count);
}

static size_t	to_malloc(char *s, char c, size_t pos)
{
	size_t	i;

	i = 0;
	while (s[pos] != c && s[pos])
	{
		pos++;
		i++;
	}
	return (i);
}

static char	*ft_splitter(char *s, char c, size_t pos)
{
	size_t	i;
	size_t	y;
	char	*tab;

	i = 0;
	y = to_malloc(s, c, pos);
	tab = (char *)malloc(sizeof(char) * y + 1);
	while (i < y)
	{
		tab[i] = s[pos + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static size_t	ft_ipos(size_t pos, const char *s, char c)
{
	while (s[pos] != c && s[pos])
		pos++;
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	pos;
	size_t	icount;

	if (!s)
		return (0);
	count = how_much_split((char *)s, c);
	icount = 0;
	pos = 0;
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	while (s[pos] == c && s[pos])
		pos++;
	while (icount < count)
	{
		split[icount] = ft_splitter((char *)s, c, pos);
		pos = ft_ipos(pos, s, c);
		while (s[pos] == c && s[pos])
			pos++;
		icount++;
	}
	split[icount] = NULL;
	return (split);
}

/*int	main(void)
{
	char	**split;
	size_t	i;
	size_t	count;

	i = 0;
	count = how_much_split("", ' ');
	printf("count = %lu\n", count);
	split = ft_split("", ' ');
	while (i < count)
	{
		printf("split = %s\n", split[i]);
		i++;
	}
	return (0);
}*/
