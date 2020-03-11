/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:39:22 by thalme            #+#    #+#             */
/*   Updated: 2020/03/11 12:59:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_initialize_values(t_arg **param)
{
	(*param)->scale = 10;
	(*param)->up = 0;
	(*param)->right = 0;
	(*param)->angle = 0;
}

int			main(int ac, char **av)
{
	t_arg	*param;

	param = (t_arg*)malloc(sizeof(t_arg));
	if (ac == 2)
		ft_read_map(av[1], &param);
	ft_initialize_values(&param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, MAX_X, MAX_Y, "fdf_test");
	ft_listen(param);
	return (0);
}
