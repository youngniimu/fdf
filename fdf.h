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
//#include "/Users/niimu/Documents/code/fdf/minilibx/mlx.h"

//MAKEFILE PATH /usr/local/lib
# include "/usr/local/include/mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"


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
	t_point			point[2];
	t_point			**map;
	int				count;
}					t_arg;

void				ft_draw_map(t_arg *param);
void				ft_bresenham_line(t_arg *param, t_point start, t_point end);
int					mouse_bindings(int button,int x,int y, t_arg *param);
int 				key_bindings(int button, t_arg *param);
t_point    			**ft_read_map(char *file_name);

#endif
