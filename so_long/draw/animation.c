/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:47:14 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/23 16:27:52 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "draw.h"
void putimg_to_win(t_draw *game)
{
    int i;
    int j = 0;
    if (!game->map)
    {
        ft_error("khrejt\n");
        exit(1);
    }
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i])
        {
            if (game->map[j][i] == 'N')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_window, game->back, i*50,j*50 );
                mlx_put_image_to_window(game->mlx,game->mlx_window,game->l3do,i*50,j*50);
            }
            if(game->map[j][i] == 'E')
                mlx_put_image_to_window(game->mlx,game->mlx_window,game->exit,i*50,j*50); 
            i++;
        }
        j++;
    }
}
void t7rak(t_draw *game)
{
    static int fr;

    if (fr <= 30)
    {
        game->l3do = mlx_xpm_file_to_image(game->mlx,"drow/1_5.xpm",&game->img_width,&game->img_height);
    }
    else  if (fr <= 60)
    {
        game->l3do = mlx_xpm_file_to_image(game->mlx,"drow/1_2.xpm",&game->img_width,&game->img_height);
    }
    else  if (fr <= 90)
    {
        game->l3do = mlx_xpm_file_to_image(game->mlx,"drow/1_3.xpm",&game->img_width,&game->img_height);
    }
    else  if (fr <= 120)
    {
        game->l3do = mlx_xpm_file_to_image(game->mlx,"drow/1_4.xpm",&game->img_width,&game->img_height);
    }
    else  if (fr <= 130)
    {
        game->l3do = mlx_xpm_file_to_image(game->mlx,"drow/1_4.xpm",&game->img_width,&game->img_height);
        if (fr == 130)
            fr = 0;
    }
    fr++;
    putimg_to_win(game);
}
int anime(t_draw *game)
{
    t7rak(game);
    return (0);
}