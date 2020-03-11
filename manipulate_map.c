/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:25:11 by thalme            #+#    #+#             */
/*   Updated: 2020/03/11 13:38:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_rotation_matrix(t_arg *param, float *i, float *j)
{
	float		temp;

	temp = *i;
	*i = *i * cos(param->angle * ANGLE) - *j * sin(param->angle * ANGLE);
	*j = *j * cos(param->angle * ANGLE) + temp * sin(param->angle * ANGLE);
}

void			ft_projection_matrix(t_arg *param)
{
	int			x;
	int			y;

	y = -1;
	while (++y < (int)param->rows)
	{
		x = -1;
		while (++x < (int)param->columns)
		{
			if (param->axis == 'x')
				ft_rotation_matrix(param, &param->map[y][x].y,
				&param->map[y][x].z);
			if (param->axis == 'y')
				ft_rotation_matrix(param, &param->map[y][x].x,
				&param->map[y][x].z);
			if (param->axis == 'z')
				ft_rotation_matrix(param, &param->map[y][x].x,
				&param->map[y][x].y);
		}
	}
	ft_bresenham_map(param->map, param);
}
