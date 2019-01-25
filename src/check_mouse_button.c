/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouse_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:17:10 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/28 16:39:46 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_elem *s_pixel)
{
	s_pixel->x_but = x;
	s_pixel->y_but = y;
	if (button == 1)
		s_pixel->press1 = 1;
	if (button == 2)
		s_pixel->gamma += 3 * 3.14 / 180;
	if (button == 4)
	{
		if (s_pixel->zoom != 0)
			s_pixel->zoom /= 1.1;
		s_pixel->z_project -= 150;
	}
	if (button == 5)
	{
		s_pixel->zoom *= 1.1;
		s_pixel->z_project += 150;
	}
	ft_fresh_s_pixel(s_pixel);
	ft_draw(s_pixel);
	return (0);
}

int	mouse_release(int button, int x, int y, t_elem *s_pixel)
{
	s_pixel->x_but = x;
	s_pixel->y_but = y;
	if (button == 1)
	{
		s_pixel->press1 = 0;
		s_pixel->check_press = 0;
	}
	ft_fresh_s_pixel(s_pixel);
	ft_draw(s_pixel);
	return (0);
}

int	mouse_move(int x, int y, t_elem *s_pixel)
{
	if (s_pixel->check_press++ == 0)
	{
		s_pixel->pre_x = s_pixel->x_but;
		s_pixel->pre_y = s_pixel->y_but;
	}
	if (s_pixel->press1 == 1)
	{
		if (s_pixel->pre_y >= y)
			s_pixel->alpha += 1 * 3.14 / 180;
		if (s_pixel->pre_y < y)
			s_pixel->alpha -= 1 * 3.14 / 180;
		if (s_pixel->pre_x >= x)
			s_pixel->beta += 1 * 3.14 / 180;
		if (s_pixel->pre_x < x)
			s_pixel->beta -= 1 * 3.14 / 180;
		s_pixel->pre_x = x;
		s_pixel->pre_y = y;
	}
	ft_fresh_s_pixel(s_pixel);
	ft_draw(s_pixel);
	return (0);
}
