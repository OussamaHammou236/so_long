/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:02:56 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/21 18:59:53 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
// void put_img(t_draw *data,int key)
// {
//         imeges(data);
//         mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x * 50,data->pos_y * 50 );
//         data->map[data->pos_y][data->pos_x] = '0';
//          if(key == 123)
//             data->map[data->pos_y][data->pos_x--] = 'P';
//         else if(key == 124)
//             data->map[data->pos_y][data->pos_x++] = 'P';
//         else if(key == 125)
//              data->map[data->pos_y++][data->pos_x] = 'P';
//         else if(key == 126)
//           data->map[data->pos_y--][data->pos_x] = 'P';
//         else if (key == 53)
//             exit(0);
// }
void walo(t_draw *data)
{
    data->img_ptr = mlx_xpm_file_to_image(data->mlx, "h.xpm", &data->img_width, &data->img_height);
     if(!data->img_ptr)
         ft_error("image not found1");
    data->player1 = mlx_xpm_file_to_image(data->mlx, ">.xpm", &data->img_width, &data->img_height);
    if(!data->player1)
        ft_error("image not found2");
    data->player = mlx_xpm_file_to_image(data->mlx, "<.xpm", &data->img_width, &data->img_height);
    if(!data->player)
        ft_error("image not found3");
    data->player2 = mlx_xpm_file_to_image(data->mlx, "->.xpm", &data->img_width, &data->img_height);
     if(!data->player2)
         ft_error("image not found4");
    data->player3 = mlx_xpm_file_to_image(data->mlx, "<-.xpm", &data->img_width, &data->img_height);
    if(!data->player3)
        ft_error("image not found5"); 
}
void lfo9(t_draw *data)
{
    walo(data); 
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x * 50,data->pos_y * 50 );
    data->pos_y--;
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x * 50,data->pos_y * 50 );
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->player1, data->pos_x * 50,data->pos_y * 50 );   
}
void ltht(t_draw *data)
{
    walo(data); 
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x * 50,data->pos_y * 50 );
    data->pos_y++;
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x*50,data->pos_y * 50 );
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->player, data->pos_x * 50,data->pos_y * 50 );
}
void lisr(t_draw *data)
{
    walo(data);
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x * 50,data->pos_y * 50 );
    data->pos_x--;
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x*50,data->pos_y * 50 );
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->player3, data->pos_x * 50,data->pos_y * 50 );
}
void limen(t_draw *data)
{
     walo(data);
     mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x*50,data->pos_y * 50 );
     data->pos_x++;
     mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_ptr, data->pos_x*50,data->pos_y * 50 );
     mlx_put_image_to_window(data->mlx, data->mlx_window, data->player2, data->pos_x * 50,data->pos_y * 50 );
}
// int hook(int key,t_draw *data)
// {
//     if(key == 124 && data->map[data->pos_y][data->pos_x + 1] != '1' && data->map[data->pos_y][data->pos_x + 1] != 'E')
//         limen(data);
//     else if(key == 125 && data->map[data->pos_y + 1][data->pos_x] != '1' && data->map[data->pos_y + 1][data->pos_x] != 'E')
//         ltht(data);
//     else if(key == 126 && data->map[data->pos_y - 1][data->pos_x] != '1' && data->map[data->pos_y - 1][data->pos_x] != 'E')
//         lfo9(data);
//     else if(key == 123 && data->map[data->pos_y][data->pos_x - 1] != '1' && data->map[data->pos_y][data->pos_x - 1] != 'E')
//         lisr(data);
//     else if(key == 53)
//         exit(0);
//     return 0;
// }
