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

static void		ft_initialize_param(t_arg **param)
{
	(*param)->scale = 10;
	(*param)->up = 0;
	(*param)->right = 0;
	(*param)->angle = 0;
}


int main(int ac, char **av)
{
	t_arg *param;
	
	param = (t_arg*)malloc(sizeof(t_arg));
	if (ac == 2)
		ft_read_map(av[1], &param);
	ft_initialize_param(&param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, MAX_X, MAX_Y, "fdf_test");

	/* int countcolumns = 0;
    int countrows = -1;
    while (++countrows < (int)param->rows)
    {
        countcolumns = -1;
        while (++countcolumns < (int)param->columns)
            printf("X %f\tY %f\tZ %f\t\t",param->map[countrows][countcolumns].x, param->map[countrows][countcolumns].y,  param->map[countrows][countcolumns].z);
        printf("\n");
    } */
	/* int countcolumns = -1;
	int countrows = 0;
	while (++countcolumns < (int)param->columns)
            printf("X %f\tY %f\tZ %f\t\t",param->map[countrows][countcolumns].x, param->map[countrows][countcolumns].y,  param->map[countrows][countcolumns].z);
        printf("\n"); */

	mlx_mouse_hook(param->win_ptr, mouse_bindings, param);
	mlx_key_hook(param->win_ptr, key_bindings, param);
	mlx_loop(param->mlx_ptr);
	return(0);
}
