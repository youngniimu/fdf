/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:50:43 by thalme            #+#    #+#             */
/*   Updated: 2020/03/05 14:50:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham_line(t_arg *param, t_point start, t_point end)
{
	float	slope;
	float	x;
	float	y;
	float	deltax;
	float	deltay;

	deltax = end.x - start.x;
	deltay = end.y - start.y;

	printf("start:\tx0:%f, y0:%f\n", start.x, start.y);
	printf("end:\tx1:%f, y1:%f\n", end.x, end.y);

	if (deltax < 0)
		ft_vswap(&end, &start, sizeof(t_point));
	/* LINE DOWN "SLOPER ERROR" */
	if (end.x == start.x)
		while(start.y++ <= end.y)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, start.x, start.y, 50000);
	slope = deltay/deltax;
	printf("%f\n", slope);

	/* GENTLE LINE */
	if (slope < 1 && slope > -1)
	{
		x = start.x;
		while(x++ < end.x)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, slope * (x - start.x) + start.y, 50000);
	}
	/* SLOPE 1 LINE */
	else if (slope == 1 || slope == -1)
	{
		while(start.x < end.x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, start.x, start.y, 50000);
			start.y++;
			start.x++;
		}
	}
	/* STEEP LINE*/
	else if (slope > 1 || slope < -1)
	{
		y = start.y;
		slope = 1 / slope;
		printf("new slope %f\n", slope);
		printf("y here:\ty0:%f, y1:%f\n", y, end.y);
		if (slope < 0)
			ft_vswap(&y, &end.y, sizeof(float));
		while(y++ < end.y)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, slope * (y - start.y) + start.x, y, 50000);
	}
}

