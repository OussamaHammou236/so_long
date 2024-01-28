/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimg_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:03:56 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/27 22:05:03 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	putimg_to_win(t_draw *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'N' || game->map[j][i] == 'n')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->back,
					i * 50, j * 50);
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->l3do,
					i * 50, j * 50);
			}
			if (game->map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->exit,
					i * 50, j * 50);
			i++;
		}
		j++;
	}
}

void	imeges(t_draw *rsm)
{
	rsm->img_ptr = mlx_xpm_file_to_image(rsm->mlx,
			"../textures/images.xpm", &rsm->img_width, &rsm->img_height);
	rsm->back = mlx_xpm_file_to_image(rsm->mlx,
			"../textures/h.xpm", &rsm->img_width, &rsm->img_height);
	rsm->player = mlx_xpm_file_to_image(rsm->mlx,
			"../textures/<.xpm", &rsm->img_width, &rsm->img_height);
	rsm->coins = mlx_xpm_file_to_image(rsm->mlx,
			"../textures/ha.xpm", &rsm->img_width, &rsm->img_height);
	rsm->exit = mlx_xpm_file_to_image(rsm->mlx,
			"../textures/doord-_1_.xpm", &rsm->img_width, &rsm->img_height);
	if (!rsm->exit || !rsm->img_ptr || !rsm->back || !rsm->player
		|| !rsm->coins)
		ft_error("images makayninch");
}
