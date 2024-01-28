/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:23:09 by ohammou-          #+#    #+#             */
/*   Updated: 2023/12/02 23:04:32 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			i;
	long int	l;

	i = 0;
	l = n;
	if (l < 0)
	{
		i += ft_putchar('-');
		l *= -1;
	}
	if (l >= 10)
	{
		i += ft_putnbr(l / 10);
		i += ft_putchar(l % 10 + '0');
	}
	if (l >= 0 && l < 10)
		i += ft_putchar(l + '0');
	return (i);
}
