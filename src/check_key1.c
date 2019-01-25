/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:14:13 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/29 13:14:16 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_z_project(t_elem *s_pixel, int k)
{
	if (k == 33)
		s_pixel->z_project -= 25;
	if (k == 30)
		s_pixel->z_project += 25;
}

void	ft_check_status_projection(t_elem *s_pixel, int k)
{
	if (k == 7)
		s_pixel->projection = 1;
	if (k == 6)
		s_pixel->projection = 0;
}

int		ft_check_k(int k, t_elem *s_pixel)
{
	if (k == 53)
	{
		ft_free_programm(s_pixel);
		close(s_pixel->fd);
		exit(1);
	}
	if (k == 33 || k == 30)
		ft_change_z_project(s_pixel, k);
	if (k == 7 || k == 6)
		ft_check_status_projection(s_pixel, k);
	if (k == 18 || k == 19 || k == 20 ||
	k == 21 || k == 23 || k == 22)
		ft_change_color(s_pixel, k);
	if (k == 126 || k == 123 || k == 125 || k == 124)
		ft_change_sx_sy(s_pixel, k);
	if (k == 84 || k == 91 || k == 86 || k == 88 || k == 85 || k == 83)
		ft_change_corner(s_pixel, k);
	if (k == 89 || k == 92)
		ft_change_z(s_pixel, k);
	if (k == 78 || k == 69 || k == 31 || k == 35)
		ft_change_zoom(s_pixel, k);
	if (k == 51)
		ft_draw_display(s_pixel);
	ft_fresh_s_pixel(s_pixel);
	return (ft_draw(s_pixel));
}
