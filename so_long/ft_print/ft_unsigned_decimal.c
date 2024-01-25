/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:05:05 by ohammou-          #+#    #+#             */
/*   Updated: 2023/12/03 17:22:29 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_decimal(unsigned int l)
{
	int	cont;

	cont = 0;
	if (l >= 10)
	{
		cont += ft_unsigned_decimal(l / 10);
		cont += ft_putchar(l % 10 + '0');
	}
	if (l >= 0 && l < 10)
		cont += ft_putchar(l + '0');
	return (cont);
}
