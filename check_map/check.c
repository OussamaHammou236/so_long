/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:31:40 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 15:44:10 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

char	*line_map(int fd)
{
	char	*line;
	char	*join;

	join = "";
	while (1)
	{
		line = get_next_line(fd);
		join = ft_strjoin(join, line, "");
		free(line);
		if (!line)
			break ;
	}
	return (join);
}

char	**ft_map(char *path)
{
	int		fd;
	char	**s;
	int		i;
	char	*join;

	i = 0;
	fd = open(path, 'r');
	join = line_map(fd);
	while (join[i])
	{
		if ((join[i] == '\n' && (join[i + 1] == '\n' || join[i + 1] == '\0'))
			|| join[0] == '\n')
			ft_error("invalid map");
		if (join[i] != '1' && join[i] != 'P' && join[i] != 'C' && join[i] != 'E'
			&& join[i] != '0' && join[i] != '\n' && join[i] != 'N')
		{
			ft_printf("invalid character --> %c", join[i]);
			exit(1);
		}
		i++;
	}
	s = ft_split(join, '\n');
	return (free(join), close(fd), s);
}

void	ft_check_length_width(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]);
	while (map[i])
	{
		if (j > ft_strlen(map[i]) || j < ft_strlen(map[i]))
			ft_error("error the len is not equal");
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			ft_error("error of width");
		i++;
	}
	if (tol(map[0]) == 0 || tol(map[i - 1]) == 0)
		ft_error("error length");
}

t_check_map	ft_check_c_p_e(char **map)
{
	int			i;
	t_check_map	check;

	i = 1;
	check.c = 0;
	check.e = 0;
	check.p = 0;
	while (map[i])
	{
		check.c += ft_strchr(map[i], 'C');
		check.p += ft_strchr(map[i], 'P');
		check.e += ft_strchr(map[i], 'E');
		i++;
	}
	if (check.c == 0)
		ft_error("error no collectible");
	if (check.p == 0 || check.p > 1)
		ft_error("error there is more than one player");
	if (check.e == 0 || check.e > 1)
		ft_error("error there is more than one map exit");
	return (check);
}

int	total_check(char *path)
{
	char		**map;
	t_check_map	check;

	map = ft_map(path);
	ft_check_length_width(map);
	check = ft_check_c_p_e(map);
	ft_free(map);
	check_siege(path);
	return (1);
}
