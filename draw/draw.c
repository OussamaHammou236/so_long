/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:18:33 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 15:53:24 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	t9adaw_smiyat(t_draw *rsm)
{
	if (rsm->map[rsm->x][rsm->y] == '1')
		mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->img_ptr, rsm->y
			* 50, rsm->x * 50);
	if (rsm->map[rsm->x][rsm->y] != '1')
		mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->back, rsm->y
			* 50, rsm->x * 50);
	if (rsm->map[rsm->x][rsm->y] == 'P')
	{
		mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->player, rsm->y
			* 50, rsm->x * 50);
		rsm->pos_x = rsm->y;
		rsm->pos_y = rsm->x;
	}
	else if (rsm->map[rsm->x][rsm->y] == 'C')
		mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->coins, rsm->y
			* 50, rsm->x * 50);
	else if (rsm->map[rsm->x][rsm->y] == 'E')
		mlx_put_image_to_window(rsm->mlx, rsm->mlx_window, rsm->exit, rsm->y
			* 50, rsm->x * 50);
}

void	writ(t_draw *rsm)
{
	rsm->x = 0;
	while (rsm->map[rsm->x])
	{
		rsm->y = 0;
		while (rsm->map[rsm->x][rsm->y])
		{
			t9adaw_smiyat(rsm);
			rsm->y++;
		}
		rsm->x++;
	}
}

int32_t	message(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
	return (0);
}

int	hook(int key, t_draw *data)
{
	char	*str;

	str = ft_itoa(data->moves);
	data->key = key;
	anime_check(key, data);
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
	mlx_string_put(data->mlx, data->mlx_window, 100, 10, 0xFFFFFF, str);
	ft_printf("moves -> %s\n", str);
	free(str);
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_draw(char *path)
{
	t_draw		rsm;
	char		**map;
	t_check_map	check;

	map = ft_map(path);
	rsm = y_x(map);
	rsm.map = map;
	rsm.key = 0;
	rsm.mlx = mlx_init();
	rsm.pos_x = 0;
	rsm.pos_y = 0;
	rsm.moves = 0;
	rsm.wall_flag = 0;
	rsm.mlx_window = mlx_new_window(rsm.mlx, rsm.tol_x * 50,
			rsm.tol_y * 50, "so_long");
	imeges(&rsm);
	writ(&rsm);
	check = ft_check_c_p_e(rsm.map);
	rsm.y_c = check.c;
	mlx_string_put(rsm.mlx, rsm.mlx_window, 20, 10, 0xFFFFFF, "moves : ");
	mlx_key_hook(rsm.mlx_window, &hook, &rsm);
	mlx_hook(rsm.mlx_window, 17, 0, &message, "game over");
	mlx_loop_hook(rsm.mlx, anime, &rsm);
	mlx_loop(rsm.mlx);
}
