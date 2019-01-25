/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_prepare.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:18:10 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/29 13:12:45 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_to_display(t_elem *s_pixel)
{
	int len;
	int i;

	i = 0;
	len = (s_pixel->column * s_pixel->row);
	while (len--)
	{
		ft_put_dot_to_brezen(s_pixel, i);
		if (s_pixel->column2 == s_pixel->column - 1)
		{
			s_pixel->row2++;
			s_pixel->column2 = 0;
		}
		else
			s_pixel->column2++;
		i++;
	}
}

void	ft_put_dot_to_brezen(t_elem *s_pixel, int i)
{
	if (s_pixel->row2 != 0)
	{
		s_pixel->x1 = s_pixel->a_x[i - s_pixel->column];
		s_pixel->y1 = s_pixel->a_y[i - s_pixel->column];
		s_pixel->x2 = s_pixel->a_x[i];
		s_pixel->y2 = s_pixel->a_y[i];
		ft_line(s_pixel);
	}
	if (s_pixel->column2 != 0)
	{
		s_pixel->x1 = s_pixel->a_x[i - 1];
		s_pixel->y1 = s_pixel->a_y[i - 1];
		s_pixel->x2 = s_pixel->a_x[i];
		s_pixel->y2 = s_pixel->a_y[i];
		ft_line(s_pixel);
	}
}

int		ft_draw(t_elem *s_pixel)
{
	ft_coordinates(s_pixel);
	ft_to_display(s_pixel);
	mlx_hook(s_pixel->win_ptr, 2, 5, ft_check_k, s_pixel);
	mlx_hook(s_pixel->win_ptr, 4, 5, mouse_press, s_pixel);
	mlx_hook(s_pixel->win_ptr, 5, 5, mouse_release, s_pixel);
	mlx_hook(s_pixel->win_ptr, 6, 5, mouse_move, s_pixel);
	mlx_loop(s_pixel->mlx_ptr);
	return (1);
}

int		ft_draw_display(t_elem *s_pixel)
{
	s_pixel->mlx_ptr = mlx_init();
	s_pixel->win_ptr = mlx_new_window(s_pixel->mlx_ptr, 2200, 1200, "mlx_42");
	s_pixel->sx = 300;
	s_pixel->sy = 100;
	s_pixel->zoom = 4.1;
	s_pixel->len = s_pixel->row * s_pixel->column;
	s_pixel->x1 = 0;
	s_pixel->x2 = 0;
	s_pixel->y1 = 0;
	s_pixel->y2 = 0;
	s_pixel->alpha = 0;
	s_pixel->beta = 0;
	s_pixel->gamma = 0;
	s_pixel->column2 = 0;
	s_pixel->row2 = 0;
	s_pixel->projection = 0;
	s_pixel->x_0 = (s_pixel->sx + s_pixel->zoom * s_pixel->column / 2);
	s_pixel->y_0 = (s_pixel->sy + s_pixel->zoom * s_pixel->row / 2);
	s_pixel->z_0 = s_pixel->arr[0];
	s_pixel->x_project = 1100;
	s_pixel->y_project = 600;
	s_pixel->z_project = 500;
	ft_malloc_for_array(s_pixel);
	s_pixel->k = 1.00;
	return (1);
}

int		ft_malloc_for_array(t_elem *s_pixel)
{
	s_pixel->check_press = 0;
	s_pixel->press1 = 0;
	s_pixel->press2 = 0;
	if (!(s_pixel->a_x = (double *)malloc(sizeof(double)
	* (s_pixel->column * s_pixel->row))))
		return (0);
	if (!(s_pixel->a_y = (double *)malloc(sizeof(double) *
	(s_pixel->column * s_pixel->row))))
		return (0);
	if (!(s_pixel->a_z = (double *)malloc(sizeof(double) *
	(s_pixel->column * s_pixel->row))))
		return (0);
	return (1);
}
