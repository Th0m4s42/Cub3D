/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:39 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:53:29 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static void	ft_inter(char const *s, unsigned int start, size_t len, char *sub)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (i >= start && y < len)
		{
			sub[y] = s[i];
			y++;
		}
		i++;
	}
	sub[y] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start || !s)
	{
		substring = malloc(1);
		if (!substring)
			return (0);
		substring[0] = '\0';
		return (substring);
	}
	if (ft_strlen(s) - start < len)
		substring = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (0);
	ft_inter(s, start, len, substring);
	return (substring);
}

/*int	main(void)
  {
  char	*test;

  test = ft_substr("tripouille", 1, 1);
  printf("%s\n", test);
  free(test);
  return (0);
  }*/
