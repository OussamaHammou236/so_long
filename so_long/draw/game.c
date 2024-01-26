/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:02:56 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 11:29:44 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	walo(t_draw *data)
{
	data->back = mlx_xpm_file_to_image(data->mlx, "../textures/h.xpm",
			&data->img_width, &data->img_height);
	data->player1 = mlx_xpm_file_to_image(data->mlx, "../textures/>.xpm",
			&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "../textures/<.xpm",
			&data->img_width, &data->img_height);
	data->player2 = mlx_xpm_file_to_image(data->mlx, "../textures/->.xpm",
			&data->img_width, &data->img_height);
	data->player3 = mlx_xpm_file_to_image(data->mlx, "../textures/<-.xpm",
			&data->img_width, &data->img_height);
	if (!data->player3 || !data->player2 || !data->player || !data->player1
		|| !data->back)
		ft_error("image not found");
}

void	lfo9(t_draw *data)
{
	walo(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	data->pos_y--;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->player1,
		data->pos_x * 50, data->pos_y * 50);
	data->moves++;
}

void	ltht(t_draw *data)
{
	walo(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	data->pos_y++;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->player,
		data->pos_x * 50, data->pos_y * 50);
	data->moves++;
}

void	lisr(t_draw *data)
{
	walo(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	data->pos_x--;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->player3,
		data->pos_x * 50, data->pos_y * 50);
	data->moves++;
}

void	limen(t_draw *data)
{
	walo(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	data->pos_x++;
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->back, data->pos_x
		* 50, data->pos_y * 50);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->player2,
		data->pos_x * 50, data->pos_y * 50);
	data->moves++;
}
