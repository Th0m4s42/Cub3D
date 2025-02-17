/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:45:40 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/12 16:11:55 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}

/*#include<string.h>
  int	main(void)
  {
  void	*blop = "abcdefghijklmnopqrstuvwxyz";
  void	*blops = "abcdefghijklmnppqrstuvwxyz";
  size_t	n = 36;

  printf("test:\n");
  if (ft_memcmp(blop, blops, n) == memcmp(blop, blops, n))
  printf("feels good to be good\n");
  else
  {	
  printf("SADNESS my boy, looks for error:\n");
  printf("the real: %i\nthe ft  : %i\n", memcmp(blop, blops, n), 
  ft_memcmp(blop, blops, n));
  }
  return (0);
  }

int main(void)
{
	char    *s1 = "salut !";
	char    *s2 = "salut_?";
	size_t    i = sizeof(s1);

	printf("memcmp       : %i\n", memcmp(s1, s2, i));

	s1 = "salut !";
	s2 = "salut_?";

	printf("ft_memcmp    : %i\n", ft_memcmp(s1, s2, i));

	return (0);
}*/
