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

void	draw_line(t_arg *param)
{
	float	slope;
	float	x;
	float	y;
	float	deltax;
	float	deltay;

	deltax = param->point[1].x - param->point[0].x;
	deltay = param->point[1].y - param->point[0].y;

	printf("start:\tx0:%f, y0:%f\n", param->point[0].x, param->point[0].y);
	printf("end:\tx1:%f, y1:%f\n", param->point[1].x, param->point[1].y);
	if (deltax < 0)
	{
		ft_vswap(&param->point[1], &param->point[0], sizeof(param->point));
	}
	/* LINE DOWN "SLOPER ERROR" */
	if (param->point[1].x == param->point[0].x)
	{
		while(param->point[0].y <= param->point[1].y)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->point[0].x, param->point[0].y, 50000);
			param->point[0].y++;
		}
	}
	slope = deltay/deltax;
	printf("%f\n", slope);

	/* GENTLE LINE */
	if (slope < 1 && slope > -1)
	{
		x = param->point[0].x;
		while(x < param->point[1].x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, slope * (x - param->point[0].x) + param->point[0].y, 50000);
			x++;
		}
	}
	/* SLOPE 1 LINE */
	else if (slope == 1 || slope == -1)
	{
		while(param->point[0].x < param->point[1].x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->point[0].x, param->point[0].y, 50000);
			param->point[0].y++;
			param->point[0].x++;
		}
	}
	/* STEEP LINE*/
	else if (slope > 1 || slope < -1)
	{
		y = param->point[0].y;
		slope = 1 / slope;
		printf("new slope %f\n", slope);
		printf("y here:\ty0:%f, y1:%f\n", y, param->point[1].y);
		if (slope < 0)
			ft_vswap(&y, &param->point[1].y, sizeof(float));
		while(y < param->point[1].y)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, slope * (y - param->point[0].y) + param->point[0].x, y, 50000);
			y++;
		}
	}
}

