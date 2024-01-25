/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:52:38 by ohammou-          #+#    #+#             */
/*   Updated: 2023/11/30 12:30:41 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_print_base(nb / 16, base);
		count += ft_putchar(base[nb % 16]);
	}
	if (nb <= 15)
		count += ft_putchar(base[nb]);
	return (count);
}
