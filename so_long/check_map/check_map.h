/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:05:09 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/17 15:15:32 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
typedef struct check
{
    int C;
    int P;
    int E;
} check_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, char *s3);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
int	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s,  int start, int len);
void    siege(char **map,int x,int y,int  plan);
void    ft_error(char *str);
void    check_siege(char *path);
char	**ft_map(char *path);
check_map    ft_check_C_P_E(char **map);
int total_check(char *path);
char    **ft_free(char **b);



#endif