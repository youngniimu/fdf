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

int main(int ac, char **av)
{
	t_arg *param;
	
	param = (t_arg*)malloc(sizeof(t_arg*));
	if (ac == 2)
		param->map = ft_read_map(av[1]);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 1200, 800, "fdf_test");
	mlx_mouse_hook(param->win_ptr, mouse_bindings, param);
	mlx_key_hook(param->win_ptr, key_bindings, param);
	mlx_loop(param->mlx_ptr);
	return(0);
}
