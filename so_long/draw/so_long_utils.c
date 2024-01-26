/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:29:26 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 15:54:01 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	put_img(t_draw *data, int key)
{
	if (key == 124 && data->map[data->pos_y][data->pos_x + 1] == 'C')
	{
		data->map[data->pos_y][data->pos_x + 1] = '0';
		data->y_c--;
	}
	else if (key == 125 && data->map[data->pos_y + 1][data->pos_x] == 'C')
	{
		data->map[data->pos_y + 1][data->pos_x] = '0';
		data->y_c--;
	}
	else if (key == 126 && data->map[data->pos_y - 1][data->pos_x] == 'C')
	{
		data->map[data->pos_y - 1][data->pos_x] = '0';
		data->y_c--;
	}
	else if (key == 123 && data->map[data->pos_y][data->pos_x - 1] == 'C')
	{
		data->map[data->pos_y][data->pos_x - 1] = '0';
		data->y_c--;
	}
}

void	check_c(int key, t_draw *data)
{
	if (data->y_c == 0)
	{
		data->exit = mlx_xpm_file_to_image(data->mlx,
				"../textures/doord_2.xpm", &data->img_width, &data->img_height);
		putimg_to_win(data);
		if (data->map[data->pos_y - 1][data->pos_x] == 'E' && key == 126)
			message("you win :)");
		if (data->map[data->pos_y][data->pos_x - 1] == 'E' && key == 123)
			message("you win :)");
		if (data->map[data->pos_y][data->pos_x + 1] == 'E' && key == 124)
			message("you win :)");
		if (data->map[data->pos_y + 1][data->pos_x] == 'E' && key == 125)
			message("you win :)");
	}
}

void	anime_check(int key, t_draw *data)
{
	put_img(data, key);
	if (data->map[data->pos_y - 1][data->pos_x] == 'N' && key == 126)
		ft_error("khesrti :(");
	if (data->map[data->pos_y][data->pos_x - 1] == 'N' && key == 123)
		ft_error("khesrti :(");
	if (data->map[data->pos_y][data->pos_x + 1] == 'N' && key == 124)
		ft_error("khesrti :(");
	if (data->map[data->pos_y + 1][data->pos_x] == 'N' && key == 125)
		ft_error("khesrti :(");
	check_c(key, data);
}

t_draw	y_x(char **map)
{
	t_draw	draw;

	draw.tol_x = 0;
	draw.tol_y = 0;
	while (map[draw.tol_y])
		draw.tol_y++;
	draw.tol_x = ft_strlen(map[0]);
	return (draw);
}
