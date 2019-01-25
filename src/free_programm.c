/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_programm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:19:51 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/29 13:06:19 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_programm(t_elem *s_pixel)
{
	free(s_pixel->arr);
	free(s_pixel->a_x);
	free(s_pixel->a_y);
	free(s_pixel->a_z);
}

void	ft_fresh_s_pixel(t_elem *s_pixel)
{
	mlx_clear_window(s_pixel->mlx_ptr, s_pixel->win_ptr);
	s_pixel->column2 = 0;
	s_pixel->row2 = 0;
	s_pixel->x_0 = (s_pixel->sx + s_pixel->zoom * s_pixel->column / 2);
	s_pixel->y_0 = (s_pixel->sy + s_pixel->zoom * s_pixel->row / 2);
	s_pixel->z_0 = s_pixel->arr[0];
}

void	ft_free(char **dep)
{
	int i;

	i = 0;
	while (dep[i] != NULL)
	{
		free(dep[i]);
		i++;
	}
	free(dep);
}

int		ft_error(t_elem *s_pixel)
{
	write(1, "error\n", 6);
	close(s_pixel->fd);
	exit(0);
	return (0);
}
