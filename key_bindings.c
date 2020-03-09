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
 	printf("button %d\n", button);
 	/*printf("first: x%d\n", param->mouse_click[0].x);
	printf("mouse_click_count is %d\n", param->mouse_click_count); */
	if (button == 4)
	{
		param->scale += 1;
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
		ft_bresenham_map(param);
	}	
	if (button == 5)
	{
		param->scale -= 1;
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
		ft_bresenham_map(param);
	}
	if (button == 1 && param->mouse_click_count == 0)
	{
		param->mouse_click[0].x = x;
		param->mouse_click[0].y = y;
		param->mouse_click_count = 1;
/* 		printf("button 1: %d, %d\n", param->mouse_click[0].x, param->mouse_click[0].y);
 */	}
	else if (button == 1 && param->mouse_click_count == 1)
	{
		param->mouse_click[1].x = x;
		param->mouse_click[1].y = y;
		ft_bresenham_line(param, param->mouse_click[0], param->mouse_click[1], 0);
		param->mouse_click[0].x = 0;
		param->mouse_click[0].y = 0;
		param->mouse_click[1].x = 0;
		param->mouse_click[1].y = 0;
		param->mouse_click_count = 0;
	}
	return(0);
}  

/* KEYBOARD BINDINGS HERE */
int key_bindings(int button, t_arg *param)
{
	
	printf("keyboard button %d\n", button);
	if (button == 123)
	{
		param->right += -1;
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
		ft_bresenham_map(param);
	}
	if (button == 124)
	{
		param->right += 1;
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
		ft_bresenham_map(param);
	}
	if (button == 125)
	{
		param->up += 1;
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
		ft_bresenham_map(param);
	}
	if (button ==126)
	{
		param->up += -1;
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
		ft_bresenham_map(param);
	}
	if (button == 35)
		ft_bresenham_map(param);
	if (button == 49)
	{
		param->mouse_click[0].x = 0;
		param->mouse_click[0].y = 0;
		param->mouse_click[1].x = 0;
		param->mouse_click[1].y = 0;
		param->mouse_click_count = 0;
	}
	if (button == 53)
    	mlx_destroy_window (param->mlx_ptr, param->win_ptr);
	if (button == 8)
		mlx_clear_window (param->mlx_ptr, param->win_ptr);
	return(0);
}
