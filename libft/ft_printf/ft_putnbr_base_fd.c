/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:17:09 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:38:27 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_putnbr_base_fd(unsigned int nbr, char *base, int fd)
{
	int	rv;

	rv = ft_count(nbr);
	if (nbr < 16)
		ft_putchar_fd(base[nbr], fd);
	if (nbr >= 16)
	{
		ft_putnbr_base_fd(nbr / 16, base, fd);
		ft_putnbr_base_fd(nbr % 16, base, fd);
	}
	return (rv);
}
