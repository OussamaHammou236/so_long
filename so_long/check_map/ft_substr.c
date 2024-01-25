/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:15:02 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/25 10:27:58 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

char	*ft_substr(char const *s,  int start, int len)
{
	int	i;
	char	*b;

	i = 0;
	if (!s || ft_strlen(s) < start || !len)
		return (malloc(1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	while (i < start)
		i++;
	start = 0;
	b = malloc(len * sizeof(char) + 1);
	if (!b)
		return (NULL);
	while (i < ft_strlen(s) && start < len)
	{
		b[start] = s[i];
		start++;
		i++;
	}
	b[start] = '\0';
	return (b);
}
