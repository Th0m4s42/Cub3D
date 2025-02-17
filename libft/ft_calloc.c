/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:20:54 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/13 16:16:17 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(1);
		return (mem);
	}
	if ((nmemb * size) < size || (nmemb * size) < nmemb)
		return (0);
	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

/*int	main(void)
  {
  size_t	test = 0;

  printf("%lu", (test - 1));
  return (0);
  }*/
