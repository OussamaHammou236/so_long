/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:34:29 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 15:37:15 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

int	tol(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[j])
	{
		if (s[j] == '1')
			i++;
		j++;
	}
	if (i == j)
		return (1);
	return (0);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
