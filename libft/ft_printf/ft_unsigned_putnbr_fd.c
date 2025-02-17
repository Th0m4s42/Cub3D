/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:36:13 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:55:08 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	static int	i = 0;

	if (n > 9)
	{
		ft_unsigned_putnbr_fd((n / 10), fd);
		ft_unsigned_putnbr_fd((n % 10), fd);
	}
	else
		i += ft_putchar_fd_int((n + '0'), fd);
	return (ft_count(n));
}
