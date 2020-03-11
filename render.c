/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:40:06 by thalme            #+#    #+#             */
/*   Updated: 2020/03/11 13:40:06 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render(t_arg *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	ft_projection_matrix(param);
}

void	ft_listen(t_arg *param)
{
	mlx_mouse_hook(param->win_ptr, mouse_bindings, param);
	mlx_key_hook(param->win_ptr, key_bindings, param);
	mlx_loop(param->mlx_ptr);
}
