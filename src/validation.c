/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:11:52 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/21 12:27:03 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_validate_char(char *str)
{
	int i;

	i = 0;
	while (str[++i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9') && str[i] != ' ' &&
		str[i] != '-' && str[i] != '+')
			return (0);
		if ('0' <= str[i] && str[i] <= '9')
			if ('0' <= str[i + 1] && str[i + 1] <= '9')
				if ('0' <= str[i + 2] && str[i + 2] <= '9')
					if ('0' <= str[i + 3] && str[i + 3] <= '9')
						if ('0' <= str[i + 4] && str[i + 4] <= '9')
							return (0);
	}
	return (1);
}

void	ft_check_the_first_column(int column, char **tmp, int i,
t_elem *s_pixel)
{
	while (tmp[++i])
		column++;
	s_pixel->column = column;
	column = 0;
}

int		ft_validate(char *str, t_elem *s_pixel)
{
	static int	k = 0;
	char		**tmp;
	int			column;
	int			i;

	tmp = NULL;
	if (ft_validate_char(str) == 0)
		return (ft_error(s_pixel));
	tmp = ft_strsplit(str, ' ');
	column = 0;
	i = -1;
	if (k++ == 0)
		ft_check_the_first_column(column, tmp, i, s_pixel);
	while (tmp[++i])
		column++;
	ft_free(tmp);
	if (column != s_pixel->column)
	{
		ft_free_programm(s_pixel);
		return (ft_error(s_pixel));
	}
	return (1);
}
