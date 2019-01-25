/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:02:36 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/21 13:34:36 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include "../lib/libft/includes/libft.h"

typedef struct	s_elem
{
	double		sx;
	double		sy;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	void		*mlx_ptr;
	void		*win_ptr;
	int			row;
	int			column;
	int			color;
	double		zoom;
	double		alpha;
	double		beta;
	double		gamma;
	int			len;
	int			column2;
	int			row2;
	double		*arr;
	double		tmp_x;
	double		tmp_y;
	double		t_x;
	double		t_y;
	double		t_z;
	double		x_0;
	double		y_0;
	double		z_0;
	double		*a_x;
	double		*a_y;
	double		*a_z;
	int			iterator;
	double		k;
	int			startx;
	int			starty;
	int			d;
	int			d1;
	int			d2;
	int			dx;
	int			dy;
	int			projection;
	double		x_project;
	double		y_project;
	double		z_project;
	int			size;
	int			press1;
	int			press2;
	int			x_but;
	int			y_but;
	double		pre_x;
	double		pre_y;
	int			check_press;
	int			fd;
}				t_elem;

int				ft_error(t_elem *s_pixel);
int				ft_malloc_for_array(t_elem *s_pixel);
void			ft_put_dot_to_brezen(t_elem *s_pixel, int i);
int				ft_check_k(int k, t_elem *s_pixel);
int				ft_draw_display(t_elem *s_pixel);
int				ft_draw(t_elem *s_pixel);
void			ft_line(t_elem *s_pixel);
int				ft_put_color(char *color);
int				ft_get_color(int color);
void			ft_free(char **dep);
void			ft_fresh_s_pixel(t_elem *s_pixel);
void			ft_swap(t_elem *s_pixel);
void			ft_draw_win(t_elem *s_pixel);
void			ft_parametrs(t_elem *s_pixel);
void			ft_colors(t_elem *s_pixel);
int				ft_inf_loop(t_elem *s_pixel);
void			ft_check_x_row(t_elem *s_pixel, int i);
void			ft_check_y_row(t_elem *s_pixel, int i);
void			ft_check_z_row(t_elem *s_pixel, int i);
int				ft_check_button(t_elem *s_pixel);
void			ft_free_programm(t_elem *s_pixel);
void			ft_change_color(t_elem *s_pixel, int k);
void			ft_change_sx_sy(t_elem *s_pixel, int k);
void			ft_change_corner(t_elem *s_pixel, int k);
void			ft_change_z(t_elem *s_pixel, int k);
void			ft_change_zoom(t_elem *s_pixel, int k);
void			ft_coordinates(t_elem *s_pixel);
void			ft_free_programm(t_elem *s_pixel);
int				ft_validate(char *line, t_elem *s_pixel);
int				mouse_press(int button, int x, int y, t_elem *s_pixel);
int				mouse_release(int button, int x, int y, t_elem *s_pixel);
int				mouse_move(int x, int y, t_elem *s_pixel);

#endif
