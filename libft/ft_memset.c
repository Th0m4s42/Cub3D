/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:41 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 17:49:00 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = (char)c;
		i++;
	}
	return (s);
}

/*#include<string.h>
  int	main()
  {
  int	c = 97;
  size_t	n = 10;
  void	*a;

  printf("%s\nbouh bouh\n", (char*)a);
  a = ft_memset(a, c, n);
  printf("%s", (char*)a);

  return (0);
  }*/
