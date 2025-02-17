/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:45:58 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:55:49 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count(unsigned long n)
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

int	ft_pointeur_base_fd(unsigned long nbr, char *base, int fd)
{
	int	rv;

	rv = ft_count(nbr);
	if (nbr < 16)
		ft_putchar_fd_int(base[nbr], fd);
	if (nbr >= 16)
	{
		ft_pointeur_base_fd(nbr / 16, base, fd);
		ft_pointeur_base_fd(nbr % 16, base, fd);
	}
	return (rv);
}

int	ft_cp(unsigned long nbr, char *base, int fd)
{
	int	rv;

	rv = 0;
	if (!nbr)
	{
		rv += ft_putstr_fd_int("(nil)", fd);
		return (rv);
	}
	rv += ft_putstr_fd_int("0x", fd);
	rv += ft_pointeur_base_fd(nbr, base, fd);
	return (rv);
}
