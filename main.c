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
	t_arg *mlw_win;
	t_point *map;

	if (ac == 2)
	{
		map = read_map(av[1]);
		mlw_win = (t_arg*)malloc(sizeof(t_arg*));
		mlw_win->mlx_ptr = mlx_init();
		mlw_win->count = 0;
		mlw_win->win_ptr = mlx_new_window(mlw_win->mlx_ptr, 1200, 800, "fdf_test");
		mlx_mouse_hook(mlw_win->win_ptr, mouse_bindings, mlw_win);
		mlx_key_hook(mlw_win->win_ptr, key_bindings, mlw_win);
		mlx_loop(mlw_win->mlx_ptr);
	}
	return(0);
}
