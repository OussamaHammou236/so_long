/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:05:17 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/17 21:55:40 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

char	*before_new_line(char *bfr)
{
	int		i;
	char	*str;

	i = 0;
	if (!bfr)
		return ("");
	while (bfr[i++] != '\n' && bfr[i])
		;
	str = malloc(i + 1);
	ft_strlcpy(str, bfr, i + 1);
	free(bfr);
	return (str);
}

char	*after_new_line(char *bfr)
{
	int		i;
	char	*str;

	i = 0;
	if (!bfr)
		return ("");
	while (*bfr != '\n' && *bfr != '\0')
		bfr++;
	if (*bfr == '\n')
	{
		str = malloc(ft_strlen(bfr + 1) + 1);
		ft_strlcpy(str, bfr + 1, ft_strlen(bfr) + 1);
		return (str);
	}
	return (NULL);
}


char	*get_rest(char *bfrcopy, int fd, char *bfr, ssize_t len)
{
	static char	*remaining;

	while (!ft_strchr(bfrcopy, '\n'))
	{
		len = read(fd, bfr, BUFFER_SIZE);
		if (len < 0)
		{
			free(remaining);
			remaining = NULL;
			return (free(bfr), NULL);
		}
		bfr[len] = '\0';
		bfrcopy = ft_strjoin(bfrcopy, remaining, bfr);
		free(remaining);
		remaining = NULL;
		if (len == 0)
			break ;
	}
	if (len == 0 && bfrcopy[0] == '\0')
		return (free(bfrcopy), free(bfr), NULL);
	remaining = after_new_line(bfrcopy);
	bfrcopy = before_new_line(bfrcopy);
	free(bfr);
	return (bfrcopy);
}

char	*get_next_line(int fd)
{
	char	*bfr;
	char	*bfrcopy;
	ssize_t	len;

	bfrcopy = "";
	len = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bfr = malloc((size_t)(BUFFER_SIZE + 1));
	if (!bfr)
		return (NULL);
	bfrcopy = get_rest(bfrcopy, fd, bfr, len);
	return (bfrcopy);
}
