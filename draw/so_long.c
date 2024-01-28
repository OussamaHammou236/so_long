/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:50:49 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/27 18:37:15 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error("wa dkhel lmap");
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".ber", 5) != 0)
		ft_error("darori lmap tkon .ber");
	total_check(av[1]);
	ft_draw(av[1]);
}
