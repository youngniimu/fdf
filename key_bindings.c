/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:54:45 by thalme            #+#    #+#             */
/*   Updated: 2020/03/05 14:54:45 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
