/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:08:37 by thalme            #+#    #+#             */
/*   Updated: 2020/03/11 13:46:55 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line_down(t_arg *param, t_point start, t_point end)
{
	while (start.y++ <= end.y)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr,
		start.x, start.y, COLOUR);
	}
}

void		ft_line_diagonal(t_arg *param, t_point start, t_point end)
{
	while (start.x < end.x)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, start.x, start.y, COLOUR);
		start.y++;
		start.x++;
	}
}

void		ft_gentle(t_arg *param, t_point start, t_point end, float slope)
{
	float	x;

	x = start.x;
	while (x++ < end.x)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr,
		x, slope * (x - start.x) + start.y, COLOUR);
	}
}

void		ft_steep(t_arg *param, t_point start, t_point end, float slope)
{
	float	y;

	y = start.y;
	slope = 1 / slope;
	if (slope < 0)
		ft_vswap(&y, &end.y, sizeof(float));
	while (y++ < end.y)
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr,
		slope * (y - start.y) + start.x, y, COLOUR);
	}
}
