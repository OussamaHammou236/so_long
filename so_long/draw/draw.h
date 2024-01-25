/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:34:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/01/25 15:15:05 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../check_map/check_map.h"

# include <mlx.h>
# include <stdlib.h>

typedef struct draw
{
	void	*mlx;
	void	*mlx_window;
	void	*img_ptr;
	void	*player;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*exit;
	void	*back;
	void	*coins;
	int     img_width; 
    int     img_height;
	char	**map;
	int		y;
	int		x;
	int		tol_x;
	int		tol_y;
	int		pos_x;
	int		pos_y;
	void	*l3do;
	int		y_C;
	void	*anime;
	int		moves;
	int		pos_x_N;
	int		pos_y_N;
	int		wall_flag;

}			t_draw;
int			anime(t_draw *game);
void		t7rak(t_draw *game);
void		imeges(t_draw *rsm);
void		limen(t_draw *data);
void		lisr(t_draw *data);
void		ltht(t_draw *data);
void		lfo9(t_draw *data);
void		walo(t_draw *data);
void		putimg_to_win(t_draw *game);
void		ft_draw(char *path);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_itoa(int n);
// int hook(int key,t_draw *data);
#endif