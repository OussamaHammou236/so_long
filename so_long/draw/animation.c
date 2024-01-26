/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:47:14 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/26 15:48:17 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	t7rak(t_draw *game)
{
	static int	fr;

	if (fr <= 20)
		game->l3do = mlx_xpm_file_to_image(game->mlx,
				"../textures/drow/1_5.xpm",
				&game->img_width, &game->img_height);
	else if (fr <= 30)
		game->l3do = mlx_xpm_file_to_image(game->mlx,
				"../textures/drow/1_2.xpm",
				&game->img_width, &game->img_height);
	else if (fr <= 40)
		game->l3do = mlx_xpm_file_to_image(game->mlx,
				"../textures/drow/1_3.xpm",
				&game->img_width, &game->img_height);
	else if (fr <= 50)
		game->l3do = mlx_xpm_file_to_image(game->mlx,
				"../textures/drow/1_4.xpm",
				&game->img_width, &game->img_height);
	else if (fr <= 60)
		game->l3do = mlx_xpm_file_to_image(game->mlx,
				"../textures/drow/1_4.xpm",
				&game->img_width, &game->img_height);
	if (!game->l3do)
		ft_error("error in imeges");
	if (fr == 70)
		fr = 0;
	fr++;
	putimg_to_win(game);
}

void	check_pos_n_p(t_draw *game)
{
	if (game->pos_x_n + 1 == game->pos_x && game->pos_y_n == game->pos_y
		&& game->map[game->pos_y_n][game->pos_x_n + 1] == '0'
		&& game->wall_flag == 0)
		ft_error("khsrti");
	if (game->pos_x_n - 1 == game->pos_x && game->pos_y_n == game->pos_y
		&& game->map[game->pos_y_n][game->pos_x_n - 1] == '0'
		&& game->wall_flag == 1)
		ft_error("khsrti");
}

void	pr(t_draw *game)
{
	check_pos_n_p(game);
	if (game->wall_flag == 0 && (game->map[game->pos_y_n][game->pos_x_n
			+ 1] == '0' || game->map[game->pos_y_n][game->pos_x_n + 1] == 'P'))
	{
		game->map[game->pos_y_n][game->pos_x_n + 1] = 'N';
		game->map[game->pos_y_n][game->pos_x_n] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->back,
			game->pos_x_n * 50, game->pos_y_n * 50);
	}
	if (game->map[game->pos_y_n][game->pos_x_n + 1] == '1')
		game->wall_flag = 1;
	if (game->wall_flag == 1 && (game->map[game->pos_y_n][game->pos_x_n
			- 1] == '0' || game->map[game->pos_y_n][game->pos_x_n - 1] == 'P'))
	{
		game->map[game->pos_y_n][game->pos_x_n - 1] = 'N';
		game->map[game->pos_y_n][game->pos_x_n] = '0';
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->back,
			game->pos_x_n * 50, game->pos_y_n * 50);
	}
	if (game->map[game->pos_y_n][game->pos_x_n - 1] == '1')
		game->wall_flag = 0;
}

void	an(t_draw *game)
{
	int	i;
	int	j;

	j = 0;
	game->pos_x_n = 0;
	game->pos_y_n = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'N')
			{
				game->pos_x_n = i;
				game->pos_y_n = j;
				pr(game);
				i++;
			}
			i++;
		}
		j++;
	}
}

int	anime(t_draw *game)
{
	static int	f;

	if (f > 140 && f < 142)
		an(game);
	t7rak(game);
	f++;
	if (f == 142)
		f = 0;
	return (0);
}
