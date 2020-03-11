/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:54:45 by thalme            #+#    #+#             */
/*   Updated: 2020/03/11 13:34:01 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_bindings(int button, int x, int y, t_arg *param)
{
	x += 0;
	y += 0;
	if (button == 4 || button == 5)
	{
		param->scale += button == 4 ? MOVE : -MOVE;
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->axis = 0;
		ft_render(param);
	}
	return (0);
}

static void	ft_handle_move(t_arg *param, int button)
{
	if (button <= 124)
		param->right += button == 123 ? -MOVE : MOVE;
	if (button >= 125)
		param->up += button == 125 ? MOVE : -MOVE;
	param->axis = 0;
	ft_render(param);
}

int			key_bindings(int button, t_arg *param)
{
	if (button == 123 || button == 124 || button == 125 || button == 126)
		ft_handle_move(param, button);
	if (button == 13 || button == 1)
	{
		param->angle = button == 1 ? 1 : -1;
		param->axis = 'x';
		ft_render(param);
	}
	if (button == 0 || button == 2)
	{
		param->angle = button == 2 ? 1 : -1;
		param->axis = 'y';
		ft_render(param);
	}
	if (button == 12 || button == 14)
	{
		param->angle = button == 14 ? 1 : -1;
		param->axis = 'z';
		ft_render(param);
	}
	if (button == 53)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	if (button == 8)
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
	return (0);
}
