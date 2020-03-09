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

//MAKEFILE PATH /Users/niimu/Documents/code/MinilibX
#include "/Users/niimu/Documents/code/fdf/minilibx/mlx.h"

//MAKEFILE PATH /usr/local/lib
//# include "/usr/local/include/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define MAX_X 1200
# define MAX_Y 800
# define SCALE 10

typedef struct		p_list
{
	float			y;
	float			x;
	int				colour;
}					k_point;

typedef struct		a_list
{
	float			y;
	float			x;
	float			z;
	int				colour;
}					t_point;

typedef struct		f_list
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			mouse_click[2];
	t_point			**map;
	int				mouse_click_count;
	size_t			rows;
	size_t			columns;
	int				scale;
	int 			right;
	int				up;
}					t_arg;

void				ft_bresenham_map(k_point **projection, t_arg *param);
void				ft_bresenham_line(t_arg *param, k_point start, k_point end, int action);
int					mouse_bindings(int button,int x,int y, t_arg *param);
int 				key_bindings(int button, t_arg *param);
void    			ft_read_map(char *file_name, t_arg **params);
void    			ft_projection_matrix(t_arg *param);
void    			ft_2d_rotation_matrix(t_arg *param);

#endif
