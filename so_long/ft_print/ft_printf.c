/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:13:06 by ohammou-          #+#    #+#             */
/*   Updated: 2023/12/03 17:10:54 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list ptr)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_putstr(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(ptr, int));
	else if (c == 'c')
		count = ft_putchar(va_arg(ptr, int));
	else if (c == 'x')
		count = ft_print_base(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count = ft_print_base(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_print_base(va_arg(ptr, unsigned long), "0123456789abcdef");
	}
	else if (c == 'u')
		count = ft_unsigned_decimal(va_arg(ptr, unsigned int));
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			count += ft_check(str[i], ptr);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
