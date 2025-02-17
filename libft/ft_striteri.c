/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:39:07 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:56:40 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// char* dans (*f) est un pointeur vers UN caractere>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !(*f))
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, (s + i));
		i++;
	}
}
