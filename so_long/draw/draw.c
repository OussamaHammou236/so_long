/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:18:33 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/25 15:17:01 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
void	imeges(t_draw *rsm)
{
	rsm->img_ptr = mlx_xpm_file_to_image(rsm->mlx, "../textures/images.xpm",
		&rsm->img_width, &rsm->img_height);
	rsm->back = mlx_xpm_file_to_image(rsm->mlx, "../textures/h.xpm",
		&rsm->img_width, &rsm->img_height);
	rsm->player = mlx_xpm_file_to_image(rsm->mlx, "../textures/<.xpm",
		&rsm->img_width, &rsm->img_height);
	rsm->coins = mlx_xpm_file_to_image(rsm->mlx, "../textures/ha.xpm",
		&rsm->img_width, &rsm->img_height);
	rsm->exit = mlx_xpm_file_to_image(rsm->mlx, "../textures/doord-_1_.xpm",
		&rsm->img_width, &rsm->img_height);
	if (!rsm->exit || !rsm->img_ptr || !rsm->back || !rsm->player
		|| !rsm->coins)
		ft_error("images makayninch");
}
void	writ(t_draw *rsm)
{
	rsm->x = 0;
	while (rsm->map[rsm->x])
	{
		rsm->y = 0;
		while (rsm->map[rsm->x][rsm->y])
		{
			if (rsm->map[rsm->x][rsm->y] == '1')
				mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->img_ptr,
					rsm->y * 50, rsm->x * 50);
			if (rsm->map[rsm->x][rsm->y] != '1')
				mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->back,
					rsm->y * 50, rsm->x * 50);
			if (rsm->map[rsm->x][rsm->y] == 'P')
			{
				mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->player,
					rsm->y * 50, rsm->x * 50);
				rsm->pos_x = rsm->y;
				rsm->pos_y = rsm->x;
			}
			else if (rsm->map[rsm->x][rsm->y] == 'C')
				mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->coins,
					rsm->y * 50, rsm->x * 50);
			else if (rsm->map[rsm->x][rsm->y] == 'E')
				mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->exit,
					rsm->y * 50, rsm->x * 50);
			rsm->y++;
		}
		rsm->x++;
	}
}

void	put_img(t_draw *data, int key)
{
	if (key == 124 && data->map[data->pos_y][data->pos_x + 1] == 'C')
	{
		data->map[data->pos_y][data->pos_x + 1] = '0';
		data->y_C--;
	}
	else if (key == 125 && data->map[data->pos_y + 1][data->pos_x] == 'C')
	{
		data->map[data->pos_y + 1][data->pos_x] = '0';
		data->y_C--;
	}
	else if (key == 126 && data->map[data->pos_y - 1][data->pos_x] == 'C')
	{
		data->map[data->pos_y - 1][data->pos_x] = '0';
		data->y_C--;
	}
	else if (key == 123 && data->map[data->pos_y][data->pos_x - 1] == 'C')
	{
		data->map[data->pos_y][data->pos_x - 1] = '0';
		data->y_C--;
	}
}
int32_t	message(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
    return 0;
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
}
void	check_C(int key, t_draw *data)
{
	if (data->y_C == 0)
	{
		data->exit = mlx_xpm_file_to_image(data->mlx, "../textures/doord_2.xpm",
			&data->img_width, &data->img_height);
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
int	hook(int key, t_draw *data)
{
    char *str;
    str = ft_itoa(data->moves);
	anime_check(key, data);
	check_C(key, data);
	if (key == 124 && data->map[data->pos_y][data->pos_x + 1] != '1'
		&& data->map[data->pos_y][data->pos_x + 1] != 'E')
		limen(data);
	else if (key == 125 && data->map[data->pos_y + 1][data->pos_x] != '1'
		&& data->map[data->pos_y + 1][data->pos_x] != 'E')
		ltht(data);
	else if (key == 126 && data->map[data->pos_y - 1][data->pos_x] != '1'
		&& data->map[data->pos_y - 1][data->pos_x] != 'E')
		lfo9(data);
	else if (key == 123 && data->map[data->pos_y][data->pos_x - 1] != '1'
		&& data->map[data->pos_y][data->pos_x - 1] != 'E')
		lisr(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, 150, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, 100, 0);
	mlx_string_put(data->mlx, data->mlx_window, 100, 10, 0xFFFFFF,str);
	ft_printf("moves -> %s\n",str);
    free(str);
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_draw(char *path)
{
	t_draw		rsm;
	char		**map;
	check_map	check;

	map = ft_map(path);
	rsm = y_x(map);
	rsm.map = map;
	rsm.mlx = mlx_init();
	rsm.pos_x = 0;
	rsm.pos_y = 0;
	rsm.moves = 0;
	rsm.wall_flag = 0;
	rsm.mlx_window = mlx_new_window(rsm.mlx, rsm.tol_x * 50, rsm.tol_y * 50,
		"so_long");
	imeges(&rsm);
	writ(&rsm);
	check = ft_check_C_P_E(rsm.map);
	rsm.y_C = check.C;
	mlx_string_put(rsm.mlx, rsm.mlx_window, 20, 10, 0xFFFFFF, "moves : ");
	mlx_key_hook(rsm.mlx_window, &hook, &rsm);
    mlx_hook(rsm.mlx_window,17,0,&message,"game over");
	mlx_loop_hook(rsm.mlx, anime, &rsm);
	mlx_loop(rsm.mlx);
}
