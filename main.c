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
 
 int	draw_box(int button,int x,int y, t_arg *param)
{
	if (button == 1)
	{
		int i;
		int j;


		i = 0;
		
		while (i < 100)
		{
			j = 0;
			while (j < 100)
			{
			
				mlx_string_put(param->mlx_ptr, param->win_ptr, i + x, y + j, 25524442 + i + j, "HELLO");
				j+= 20;
			}
			i+=20;
		}
	}
	return(0);
}  

int main()
{
	t_arg *mlw_win;
//	void *mlx_ptr;
//	void *win_ptr;

	mlw_win = (t_arg*)malloc(sizeof(t_arg*));
	mlw_win->mlx_ptr = mlx_init();
	mlw_win->win_ptr = mlx_new_window(mlw_win->mlx_ptr, 500, 500, "fdf");
	mlx_mouse_hook(mlw_win->win_ptr, draw_box, mlw_win);
	mlx_loop(mlw_win->mlx_ptr);
}
