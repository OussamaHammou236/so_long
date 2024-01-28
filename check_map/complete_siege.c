/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_siege.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:17:15 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 15:37:48 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

size_t	pos(char **map)
{
	size_t	y;

	y = 0;
	while (map[y])
	{
		if (ft_strchr(map[y], 'P'))
			return (y);
		y++;
	}
	return (0);
}

int	count_h(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

void	siege(char **map, int x, int y, int plan)
{
	if (plan == 1)
		if (y < 0 || x < 0 || x >= ft_strlen(map[0]) || y >= count_h(map)
			|| map[y][x] == '1' || map[y][x] == 'A')
			return ;
	if (plan == 2)
		if (y < 0 || x < 0 || x >= ft_strlen(map[0]) || y >= count_h(map)
			|| map[y][x] == '1' || map[y][x] == 'A' || map[y][x] == 'E')
			return ;
	map[y][x] = 'A';
	siege(map, x, y + 1, plan);
	siege(map, x + 1, y, plan);
	siege(map, x - 1, y, plan);
	siege(map, x, y - 1, plan);
}

void	check_path_of_e(char **map1, int h, int x, int y)
{
	siege(map1, x, y, 1);
	while (map1[h])
	{
		if (ft_strchr(map1[h], 'E'))
			ft_error("tri9 msdoda");
		h++;
	}
	ft_free(map1);
}

void	check_siege(char *path)
{
	char	**map;
	char	**map1;
	int		y;
	int		x;
	int		h;

	map = ft_map(path);
	map1 = ft_map(path);
	y = pos(map);
	x = 0;
	h = 0;
	while (map[y][x] && map[y][x] != 'P')
		x++;
	if (y == ft_strlen(map[0]))
		ft_error("lkharita morba3");
	siege(map, x, y, 2);
	while (map[h])
	{
		if (ft_strchr(map[h], 'C'))
			ft_error("tri9 msdoda");
		h++;
	}
	h = 0;
	check_path_of_e(map1, h, x, y);
	ft_free(map);
}
