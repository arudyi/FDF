/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:57:41 by arudyi            #+#    #+#             */
/*   Updated: 2018/12/29 13:06:47 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_put_color(char *color)
{
	int col;

	col = 0;
	if (*color == '\0' || color == NULL)
		exit(1);
	if (ft_strcmp(color, "blue") == 0)
		col = 0x0000FF;
	if (ft_strcmp(color, "green") == 0)
		col = 0x00FF00;
	if (ft_strcmp(color, "red") == 0)
		col = 0xFF0000;
	if (ft_strcmp(color, "yellow") == 0)
		col = 0xFFFF00;
	if (ft_strcmp(color, "purple") == 0)
		col = 0xFF00FF;
	if (ft_strcmp(color, "white") == 0)
		col = 0xFFFFFF;
	return (ft_get_color(col));
}

int	ft_get_color(int color)
{
	static int col = 0;
	static int i = 0;

	if (i == 0)
	{
		col = color;
		i++;
	}
	return (col);
}

int	ft_add_element(char *str, t_elem *s_pixel)
{
	char		**tmp;
	static int	k = 0;
	int			i;

	i = -1;
	tmp = ft_strsplit(str, ' ');
	while (tmp[++i])
	{
		s_pixel->arr[k] = ft_atoi(tmp[i]);
		k++;
	}
	ft_free(tmp);
	return (1);
}

int	ft_read_matrix(int fd, char *line, t_elem *s_pixel)
{
	while (get_next_line(fd, &line))
	{
		if (ft_validate(line, s_pixel))
		{
			if (ft_add_element(line, s_pixel) == 0)
			{
				free(line);
				ft_free_programm(s_pixel);
				return (ft_error(s_pixel));
			}
		}
		else
		{
			free(line);
			return (ft_error(s_pixel));
		}
		free(line);
		s_pixel->row++;
	}
	if (ft_draw_display(s_pixel) == 0)
		return (ft_error(s_pixel));
	if (ft_draw(s_pixel) == 0)
		return (ft_error(s_pixel));
	system("leaks a.out");
	return (1);
}

int	main(int ac, char **av)
{
	char	*line;
	int		size;
	int		i;
	t_elem	*s_pixel;

	line = NULL;
	i = 0;
	if (!(s_pixel = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	size = 0;
	if (ac == 3)
		ft_error(s_pixel);
	s_pixel->fd = open(av[1], O_RDONLY);
	if (s_pixel->fd < 0)
		ft_error(s_pixel);
	s_pixel->row = 0;
	s_pixel->size = 100000;
	s_pixel->color = ft_put_color("white");
	if (!(s_pixel->arr = (double *)malloc(sizeof(double) * s_pixel->size)))
		return (ft_error(s_pixel));
	if (ft_read_matrix(s_pixel->fd, line, s_pixel) == 0)
		ft_error(s_pixel);
	close(s_pixel->fd);
	return (0);
}
