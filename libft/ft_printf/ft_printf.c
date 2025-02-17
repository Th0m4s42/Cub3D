/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:28:57 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:54:23 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* printf return an int equal to the numbers of caractere print,
 * exclude null terminated bytes
 *
 * printf est une fonction variadic "..." signifie qu'elle prend un nombre 
 * indefini de parametre:
 * 0 argument, differents type d'argument sont possible !
 *
 * fonction autorise : "malloc, free, write,
 * va_start, va_arg, va_copy, va_end"
 * libft autorise
 */

// void va_start(va_list arg, last_know parameter from ft_printf)

int	ft_printf(const char *format, ...)
{
	int		return_value;
	int		i;
	va_list	arg;

	i = 0;
	return_value = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			return_value += ft_arborescent(arg, format, i);
		}
		else
			return_value += ft_putchar_fd_int(format[i], 1);
		i++;
	}
	va_end(arg);
	return (return_value);
}

int	ft_arborescent(va_list arg, const char *format, int i)
{
	int	rv;

	rv = 0;
	if (format[i] == 'c')
		rv += ft_putchar_fd_int(va_arg(arg, int), 1);
	if (format[i] == 's')
		rv += ft_putstr_fd_int(va_arg(arg, char *), 1);
	if (format[i] == 'p')
		rv += ft_cp(va_arg(arg, unsigned long), "0123456789abcdef", 1);
	if (format[i] == 'd')
		rv += ft_putnbr_fd_int(va_arg(arg, int), 1);
	if (format[i] == 'i')
		rv += ft_putnbr_fd_int(va_arg(arg, int), 1);
	if (format[i] == 'u')
		rv += ft_unsigned_putnbr_fd(va_arg(arg, unsigned int), 1);
	if (format[i] == 'x')
		rv += ft_putnbr_base_fd(va_arg(arg, unsigned int),
				"0123456789abcdef", 1);
	if (format[i] == 'X')
		rv += ft_putnbr_base_fd(va_arg(arg, unsigned int),
				"0123456789ABCDEF", 1);
	if (format[i] == '%')
		rv += ft_putchar_fd_int(format[i], 1);
	return (rv);
}

/*
int main (void)
{
	printf("%i", printf("%s | banane%lhh", "salut"));
	printf("\n");
	printf("%i", ft_printf("%s | banane%lhh", "salut"));

	return (0);
}


int	main(void)
{
	int	r = 0;
	int	f = 0;
	int	*ptr = NULL;

        r = printf("the real = %p\n", ptr);
        f = ft_printf("the fake = %p\n", ptr);
	printf("real = %d, fake = %d", r, f);
	return (0);
}*/
