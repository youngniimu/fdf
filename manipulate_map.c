/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:25:11 by thalme            #+#    #+#             */
/*   Updated: 2020/03/09 11:25:12 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static k_point     **ft_allocate_projection(size_t rows, size_t columns)
{
    k_point **map;
    int     count;

    count = -1;
    map = (k_point**)malloc(sizeof(k_point*) * rows);
    while(++count < (int)rows)
        map[count] = (k_point*)malloc(sizeof(k_point) * columns);
    return(map);
}

void    ft_projection_matrix(t_arg *param)
{
        int x;
        int y;
        k_point **projection;        

        projection = ft_allocate_projection(param->rows, param->columns);
        y = -1;
        while(++y < (int)param->rows)
        {
            x = -1;
            while(x++ < (int)param->columns)
            {
                projection[y][x].x =  param->map[y][x].x * 1 + param->map[y][x].y * 0 + param->map[y][x].z * 1;
                projection[y][x].y = param->map[y][x].x * 0 + param->map[y][x].y * 1 + param->map[y][x].z * 1;
            }
        }
        ft_bresenham_map(projection, param);
        free(projection);
}

void    ft_2d_rotation_matrix(t_arg *param)
{
        int x;
        int y;
        k_point **projection;        

        projection = ft_allocate_projection(param->rows, param->columns);
        y = -1;
        while(++y < (int)param->rows)
        {
            x = -1;
            while(x++ < (int)param->columns)
            {
                projection[y][x].x = -1 * param->map[y][x].x + 1 * param->map[y][x].y;
                projection[y][x].y = 1 * param->map[y][x].x + -1 * param->map[y][x].y;
            }
        }
        ft_bresenham_map(projection, param);
        free(projection);
}