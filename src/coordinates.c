/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:15:29 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/28 16:52:37 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_x_row(t_elem *s_pixel, int i)
{
	s_pixel->t_y = (s_pixel->y_0) + (s_pixel->a_y[i] - s_pixel->y_0) *
	cos(s_pixel->alpha) + ((s_pixel->arr[i] - s_pixel->z_0) * s_pixel->k
	* (s_pixel->zoom / 5)) * sin(s_pixel->alpha);
	s_pixel->t_z = (s_pixel->z_0) + (-1 * (s_pixel->a_y[i] - s_pixel->y_0)) *
	sin(s_pixel->alpha) + ((s_pixel->arr[i] * s_pixel->k * (s_pixel->zoom / 5))
	- s_pixel->z_0) * cos(s_pixel->alpha);
	s_pixel->a_y[i] = s_pixel->t_y;
	s_pixel->a_z[i] = s_pixel->t_z;
	if (s_pixel->projection == 1)
	{
		s_pixel->a_x[i] = s_pixel->x_project + (s_pixel->z_project /
		(s_pixel->z_project - s_pixel->a_z[i]) * (s_pixel->a_x[i] -
		s_pixel->x_project));
		s_pixel->a_y[i] = s_pixel->y_project + (s_pixel->z_project /
		(s_pixel->z_project - s_pixel->a_z[i]) * (s_pixel->a_y[i] -
		s_pixel->y_project));
	}
}

void	ft_check_y_row(t_elem *s_pixel, int i)
{
	s_pixel->t_x = (s_pixel->x_0) + (s_pixel->a_x[i] - s_pixel->x_0) *
	cos(s_pixel->beta) + ((s_pixel->arr[i] - s_pixel->z_0) * s_pixel->k
	* (s_pixel->zoom / 5)) * sin(s_pixel->beta);
	s_pixel->t_z = (s_pixel->z_0) + (-1 * (s_pixel->a_x[i] - s_pixel->x_0)) *
	sin(s_pixel->beta) + ((s_pixel->arr[i] * s_pixel->k * (s_pixel->zoom / 5))
	- s_pixel->z_0) * cos(s_pixel->beta);
	s_pixel->a_x[i] = s_pixel->t_x;
	s_pixel->a_z[i] = s_pixel->t_z;
	if (s_pixel->projection == 1)
	{
		s_pixel->a_x[i] = s_pixel->x_project + (s_pixel->z_project /
		(s_pixel->z_project - s_pixel->a_z[i]) * (s_pixel->a_x[i] -
		s_pixel->x_project));
		s_pixel->a_y[i] = s_pixel->y_project + (s_pixel->z_project /
		(s_pixel->z_project - s_pixel->a_z[i]) * (s_pixel->a_y[i] -
		s_pixel->y_project));
	}
}

void	ft_check_z_row(t_elem *s_pixel, int i)
{
	s_pixel->t_x = (s_pixel->x_0) + (s_pixel->a_x[i] - s_pixel->x_0) *
	cos(s_pixel->gamma) + (-1 * (s_pixel->a_y[i] - s_pixel->y_0)) *
	sin(s_pixel->gamma);
	s_pixel->t_y = (s_pixel->y_0) - (-1 * (s_pixel->a_x[i] - s_pixel->x_0))
	* sin(s_pixel->gamma) + (s_pixel->a_y[i] - s_pixel->y_0) *
	cos(s_pixel->gamma);
	s_pixel->a_x[i] = s_pixel->t_x;
	s_pixel->a_y[i] = s_pixel->t_y;
}

void	ft_find_dot(t_elem *s_pixel, int i)
{
	s_pixel->a_x[i] = s_pixel->sx + (s_pixel->zoom * s_pixel->column2);
	s_pixel->a_y[i] = s_pixel->sy + (s_pixel->zoom * s_pixel->row2);
	ft_check_x_row(s_pixel, i);
	ft_check_y_row(s_pixel, i);
	ft_check_z_row(s_pixel, i);
}

void	ft_coordinates(t_elem *s_pixel)
{
	int i;
	int len;

	i = 0;
	len = s_pixel->column * s_pixel->row;
	while (len--)
	{
		ft_find_dot(s_pixel, i);
		if (s_pixel->column2 == s_pixel->column - 1)
		{
			s_pixel->row2++;
			s_pixel->column2 = 0;
		}
		else
			s_pixel->column2++;
		i++;
	}
	s_pixel->row2 = 0;
}
