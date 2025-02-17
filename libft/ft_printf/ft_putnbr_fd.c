/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:06:36 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:38:24 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count(int n)
{
	int		count;
	long	num;

	num = n;
	count = 1;
	if (num < 0)
	{
		count = 2;
		num = -num;
	}
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_fd_int(int n, int fd)
{
	int	count;

	count = ft_count(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n > 9)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putnbr_fd((n % 10), fd);
		}
		else
			ft_putchar_fd((n + '0'), fd);
	}
	return (count);
}
