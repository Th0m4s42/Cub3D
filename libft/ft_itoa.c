/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:48:15 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/15 18:52:22 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static int	size_tab(int n)
{
	int	i;

	i = 1;
	if (n > 0)
	{
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n < 0)
	{
		while (n < -9)
		{
			n = n / 10;
			i++;
		}
	}
	else
		i++;
	if (n < 0)
		i++;
	return (i);
}

static char	*to_malloc(int n)
{
	int		size_malloc;
	char	*num;

	if (n == 0)
		size_malloc = 1;
	else
		size_malloc = size_tab(n);
	num = (char *)malloc(sizeof(char) * (size_malloc + 1));
	if (!num)
		return (0);
	ft_bzero(num, size_malloc + 1);
	return (num);
}

static void	recursive(int n, char *num)
{
	if (n == -2147483648)
	{
		num[1] = '2';
		recursive(147483648, num);
	}
	else
	{
		if (n < 0)
			n = -n;
		if (n > 9)
		{
			recursive((n / 10), num);
			recursive((n % 10), num);
		}
		else
			num[ft_strlen(num)] = (n + '0');
	}
}

char	*ft_itoa(int n)
{
	char	*num;

	num = to_malloc(n);
	if (!num)
		return (0);
	if (n < 0)
		num[0] = '-';
	recursive(n, num);
	return (num);
}

/*int	main(void)
{
	char	*tab;
	int	n;

	n = 0;
	tab = ft_itoa(n);
	printf("n = %i, itoa = %s\n", n, tab);
	return (0);
}*/
