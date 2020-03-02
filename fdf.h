/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:39:42 by thalme            #+#    #+#             */
/*   Updated: 2020/01/07 11:00:03 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_
# define _FDF_

#include "/Users/niimu/Documents/code/fdf/minilibx/mlx.h"
//# include "/usr/local/include/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		a_list
{
	float				y;
	float				x;
	float				z;
	float				colour;
}					t_point;

typedef struct		f_list
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			point[2];
	int				count;
}					t_arg;


#endif
