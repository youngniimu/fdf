/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:39:22 by thalme            #+#    #+#             */
/*   Updated: 2020/01/07 13:57:02 by thalme           ###   ########.fr       */
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

void	draw_square(t_arg *param)
{
/* 	printf("draw\nfrom %d, %d to ", param->point[0].x, param->point[0].y);
	printf("%d, %d\n", param->point[1].x, param->point[1].y); */

	float x;
	float y;
	float i;
	float j;

	j = 0;
	x = param->point[0].x;
	y = param->point[0].y;
	while(j < param->point[1].y - param->point[0].y)
	{
		i = 0;
		while(i < param->point[1].x - param->point[0].x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + i, y + j, 46363435 + 150);
			i++;
		}
		j++;
	}
}

int	mouse_bindings(int button,int x,int y, t_arg *param)
{	
 	/* printf("button %d, x: %d, y: %d\n\n", button, x, y);
 	printf("first: x%d\n", param->point[0].x);
	printf("count is %d\n", param->count); */
	if (button == 1 && param->count == 0)
	{
		param->point[0].x = x;
		param->point[0].y = y;
		param->count = 1;
/* 		printf("button 1: %d, %d\n", param->point[0].x, param->point[0].y);
 */	}
	else if (button == 2 && param->count == 1)
	{
		param->point[1].x = x;
		param->point[1].y = y;
		draw_square(param);
		param->point[0].x = 0;
		param->point[0].y = 0;
		param->point[1].x = 0;
		param->point[1].y = 0;
		param->count = 0;
/* 		printf("button 2: %d, %d\n", param->point[1].x, param->point[1].y);
 */	}
	else if (button == 1 && param->count == 1)
	{
		param->point[1].x = x;
		param->point[1].y = y;
		draw_line(param);
		param->point[0].x = 0;
		param->point[0].y = 0;
		param->point[1].x = 0;
		param->point[1].y = 0;
		param->count = 0;
	}
	return(0);
}  

/* KEYBOARD BINDINGS HERE */
int key_bindings(int button, t_arg *param)
{
	printf("keyboard button %d\n", button);
	if (button == 49)
	{
		param->point[0].x = 0;
		param->point[0].y = 0;
		param->point[1].x = 0;
		param->point[1].y = 0;
		param->count = 0;
	
	}
	if (button == 53)
       mlx_destroy_window (param->mlx_ptr, param->win_ptr);
	if (button == 8)
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
	return(0);
}

int main()
{
	t_arg *mlw_win;

	mlw_win = (t_arg*)malloc(sizeof(t_arg*));
	mlw_win->mlx_ptr = mlx_init();
	mlw_win->count = 0;
	mlw_win->win_ptr = mlx_new_window(mlw_win->mlx_ptr, 1200, 800, "fdf_test");
	mlx_mouse_hook(mlw_win->win_ptr, mouse_bindings, mlw_win);
	mlx_key_hook(mlw_win->win_ptr, key_bindings, mlw_win);
	mlx_loop(mlw_win->mlx_ptr);
}
