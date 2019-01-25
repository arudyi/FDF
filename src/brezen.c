/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:06:26 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/28 16:35:55 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_line_low(t_elem *s_pixel)
{
	s_pixel->x2 = s_pixel->x1;
	s_pixel->y2 = s_pixel->y1;
	s_pixel->iterator = 1;
	while (s_pixel->iterator <= s_pixel->dx)
	{
		if (s_pixel->d >= 0)
		{
			s_pixel->d += s_pixel->d2;
			s_pixel->y2 += s_pixel->starty;
		}
		else
			s_pixel->d += s_pixel->d1;
		s_pixel->iterator++;
		s_pixel->x2 += s_pixel->startx;
		mlx_pixel_put(s_pixel->mlx_ptr, s_pixel->win_ptr, s_pixel->x2,
		s_pixel->y2, s_pixel->color);
	}
}

void	ft_print_line_high(t_elem *s_pixel)
{
	s_pixel->y2 = s_pixel->y1;
	s_pixel->x2 = s_pixel->x1;
	s_pixel->iterator = 1;
	while (s_pixel->iterator <= s_pixel->dy)
	{
		if (s_pixel->d >= 0)
		{
			s_pixel->d += s_pixel->d2;
			s_pixel->x2 += s_pixel->startx;
		}
		else
			s_pixel->d += s_pixel->d1;
		s_pixel->iterator++;
		s_pixel->y2 += s_pixel->starty;
		mlx_pixel_put(s_pixel->mlx_ptr, s_pixel->win_ptr, s_pixel->x2,
		s_pixel->y2, s_pixel->color);
	}
}

void	ft_line(t_elem *s_pixel)
{
	s_pixel->dx = abs(s_pixel->x2 - s_pixel->x1);
	s_pixel->dy = abs(s_pixel->y2 - s_pixel->y1);
	s_pixel->startx = s_pixel->x2 >= s_pixel->x1 ? 1 : -1;
	s_pixel->starty = s_pixel->y2 >= s_pixel->y1 ? 1 : -1;
	s_pixel->d = s_pixel->dy <= s_pixel->dx ? (s_pixel->dy << 1)
	- s_pixel->dx : (s_pixel->dx << 1) - s_pixel->dy;
	s_pixel->d1 = s_pixel->dy <= s_pixel->dx ? s_pixel->dy << 1
	: s_pixel->dx << 1;
	s_pixel->d2 = s_pixel->dy <= s_pixel->dx ?
	(s_pixel->dy - s_pixel->dx) << 1 :
	(s_pixel->dx - s_pixel->dy) << 1;
	mlx_pixel_put(s_pixel->mlx_ptr, s_pixel->win_ptr, s_pixel->x1,
	s_pixel->y1, s_pixel->color);
	if (s_pixel->dy <= s_pixel->dx)
		ft_print_line_low(s_pixel);
	else
		ft_print_line_high(s_pixel);
}
