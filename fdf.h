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
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define MAX_X 1200
# define MAX_Y 800
# define MOVE 2
# define ANGLE 0.1
# define COLOUR 50000

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
	t_point			**map;
	size_t			rows;
	size_t			columns;
	float			angle;
	int				scale;
	int 			right;
	int				up;
}					t_arg;

void				ft_bresenham_map(t_point **projection, t_arg *param);
void				ft_bresenham_line(t_arg *param, t_point start, t_point end);
void    			ft_read_map(char *file_name, t_arg **params);
void    			ft_projection_matrix(t_arg *param, char rotation);
void		ft_line_down(t_arg *param, t_point start, t_point end);
void		ft_gentle_line(t_arg *param, t_point start, t_point end, float slope);
void		ft_steep_line(t_arg *param, t_point start, t_point end, float slope);
void		ft_line_diagonal(t_arg *param, t_point start, t_point end);

int					mouse_bindings(int button,int x,int y, t_arg *param);
int 				key_bindings(int button, t_arg *param);

#endif
