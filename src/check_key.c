/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:13:24 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/28 16:36:43 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_color(t_elem *s_pixel, int key)
{
	if (key == 18)
		s_pixel->color = 0x0000FF;
	if (key == 19)
		s_pixel->color = 0xFF0000;
	if (key == 20)
		s_pixel->color = 0xFFFF00;
	if (key == 21)
		s_pixel->color = 0x00FF00;
	if (key == 23)
		s_pixel->color = 0xFF00FF;
	if (key == 22)
		s_pixel->color = 0xFFFFFF;
}

void	ft_change_sx_sy(t_elem *s_pixel, int key)
{
	if (key == 126)
		s_pixel->sy = s_pixel->sy - 10;
	if (key == 123)
		s_pixel->sx = s_pixel->sx - 10;
	if (key == 125)
		s_pixel->sy = s_pixel->sy + 10;
	if (key == 124)
		s_pixel->sx = s_pixel->sx + 10;
}

void	ft_change_corner(t_elem *s_pixel, int key)
{
	if (key == 84)
		s_pixel->alpha -= 5 * 3.14 / 180;
	if (key == 91)
		s_pixel->alpha += 5 * 3.14 / 180;
	if (key == 86)
		s_pixel->beta -= 5 * 3.14 / 180;
	if (key == 88)
		s_pixel->beta += 5 * 3.14 / 180;
	if (key == 83)
		s_pixel->gamma -= 5 * 3.14 / 180;
	if (key == 85)
		s_pixel->gamma += 5 * 3.14 / 180;
}

void	ft_change_z(t_elem *s_pixel, int key)
{
	int i;
	int len;

	len = s_pixel->row * s_pixel->column;
	i = 0;
	if (key == 89)
		s_pixel->k -= 2;
	if (key == 92)
		s_pixel->k += 2;
}

void	ft_change_zoom(t_elem *s_pixel, int key)
{
	if (key == 78)
	{
		if (s_pixel->zoom != 0)
			s_pixel->zoom /= 1.1;
		s_pixel->z_project -= 150;
	}
	if (key == 69)
	{
		s_pixel->zoom *= 1.1;
		s_pixel->z_project += 150;
	}
}
