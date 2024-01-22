/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:31:40 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/22 22:36:10 by ohammou-         ###   ########.fr       */
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

char	**ft_map(char *path)
{
	int		fd;
	char	*line;
	char	*join;
	char	**s;
	int		i;
	
	i	=	0;
	fd = open(path, 'r');
	join = "";
	while (1)
	{
		line = get_next_line(fd);
		join = ft_strjoin(join, line, "");
		free(line);
		if (!line)
			break ;
	}
	while(join[i])
	{
		if((join[i] == '\n' && (join[i + 1] == '\n' || join[i + 1] == '\0')) || join[0] == '\n')
			ft_error("invalid map");
		if(join[i] != '1' && join[i] != 'P' && join[i] != 'C' && join[i] != 'E' && join[i] != '0' && join[i] != '\n' && join[i] != 'N')
		{
			printf("invalid character --> %c",join[i]);
			exit(1);
		}
		i++;
	}
	s = ft_split(join, '\n');
	return (free(join),close(fd),s);
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
check_map ft_check_C_P_E(char **map)
{
	int i;
	i	=	1;
	check_map check;
	check.C = 0;
	check.E = 0;
	check.P = 0;
	
	while(map[i])
	{
		check.C += ft_strchr(map[i],'C');
		check.P += ft_strchr(map[i],'P');
		check.E += ft_strchr(map[i],'E');
		i++;
	}
	if(check.C == 0)
		ft_error("error no collectible");
	if(check.P == 0 || check.P > 1)
		ft_error("error there is more than one player");
	if(check.E == 0 || check.E > 1)
		ft_error("error there is more than one map exit");
	return check;
}
int total_check(char *path)
{
	char **map;
	check_map h;
	map = ft_map(path);
	ft_check_length_width(map);
	h = ft_check_C_P_E(map);
	check_siege(path);
	return 1;
}
// int main()
// {
// 	printf("%d",total_check("map.ber"));
// }
