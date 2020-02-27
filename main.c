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
 
 int	draw_box(int key, void *param)
{
	int y;
	int x;

	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 100)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, y, x, 255);
			x++;
		}
		y++;
	}
	return (0);
}  

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	mlx_string_put(mlx_ptr, win_ptr, 0, 0, 25524442 , "HELLO");
	mlx_mouse_hook(win_ptr, draw_box, (void *)0);

	mlx_loop(mlx_ptr);
}
