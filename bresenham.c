/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:50:43 by thalme            #+#    #+#             */
/*   Updated: 2020/03/05 14:50:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_handle_origo_move_zoom(t_arg *param, t_point *start, t_point *end)
{
	(*start).x += param->right;
	(*start).y += param->up;
	(*end).x += param->right;
	(*end).y += param->up;
	(*start).x *= param->scale;
	(*start).y *= param->scale;
	(*end).x *= param->scale;
	(*end).y *= param->scale;
	(*start).x += (MAX_X / 2);
	(*end).x += (MAX_X / 2);
	(*start).y += (MAX_Y / 2);
	(*end).y += (MAX_Y / 2);
}

void		ft_bresenham_line(t_arg *param, t_point start, t_point end)
{
	float	slope;
	float	deltax;
	float	deltay;

	ft_handle_origo_move_zoom(param, &start, &end);
	deltax = end.x - start.x;
	deltay = end.y - start.y;
	slope = deltay/deltax;
	if (deltax < 0)
		ft_vswap(&end, &start, sizeof(t_point));
	if (end.x == start.x)
		ft_line_down(param, start, end);
	if (slope < 1 && slope > -1)
		ft_gentle_line(param, start, end, slope);
	else if (slope == 1 || slope == -1)
		ft_line_diagonal(param, start, end);
	else if (slope > 1 || slope < -1)
		ft_steep_line(param, start, end, slope);
}

void        ft_bresenham_map(t_point **projection, t_arg *param)
{
    int     i;
    int     j;

    i = -1;
    while(++i < (int)param->rows)
    {     
        j = -1;
        while(++j < (int)param->columns)
        {
            if (j + 1 < (int)param->columns)
                ft_bresenham_line(param, projection[i][j], projection[i][j + 1]);
            if (i + 1 < (int)param->rows)
                ft_bresenham_line(param, projection[i][j], projection[i + 1][j]);   
        }
    }
}