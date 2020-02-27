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
#include "/usr/local/include/mlx.h"

void	draw_line(t_arg *param)
{
	printf("draw\nfrom %d, %d to ", param->point[0].x, param->point[0].y);
	printf("%d, %d\n", param->point[1].x, param->point[1].y);

	int x;
	int y;
	int i;
	int j;

	j = 0;
	x = param->point[0].x;
	y = param->point[0].y;
	while(j < param->point[1].y - param->point[0].y)
	{
		i = 0;
		while(i < param->point[1].x - param->point[0].x)
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x + i, y + j, 3232532 + x + y);
			i++;
		}
		j++;
	}
}

int	draw_box(int button,int x,int y, t_arg *param)
{	
/* 	printf("button %d, x: %d, y: %d\n\n", button, x, y);
 	printf("first: x%d\n", param->point[0].x);*/
	if (button == 1)
	{
		param->point[0].x = x;
		param->point[0].y = y;
		printf("button 1: %d, %d\n", param->point[0].x, param->point[0].y);
	}
	if (button == 2)
	{
		param->point[1].x = x;
		param->point[1].y = y;
		printf("button 2: %d, %d\n", param->point[1].x, param->point[1].y);
	}
	if ((param->point[0].x) && (param->point[1].x))
	{
		draw_line(param);
		param->point[0].x = 0;
		param->point[0].y = 0;
		param->point[1].x = 0;
		param->point[1].y = 0;
	}
	return(0);
}  

int main()
{
	t_arg *mlw_win;

	mlw_win = (t_arg*)malloc(sizeof(t_arg*));
	mlw_win->mlx_ptr = mlx_init();
	mlw_win->win_ptr = mlx_new_window(mlw_win->mlx_ptr, 500, 500, "fdf");
	mlx_mouse_hook(mlw_win->win_ptr, draw_box, mlw_win);
	mlx_loop(mlw_win->mlx_ptr);
}
