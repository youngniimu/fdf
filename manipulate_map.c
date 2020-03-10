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



void    ft_projection_matrix(t_arg *param, char rotation)
{
    int x;
    int y;
    float temp;

    y = -1;
    while(++y < (int)param->rows)
    {
        x = -1;
        while(++x < (int)param->columns)
        {
            if (rotation == 'x')
            {
                temp = param->map[y][x].y;
                param->map[y][x].y = param->map[y][x].y * cos(param->angle * ANGLE) - param->map[y][x].z * sin(param->angle * ANGLE);
                param->map[y][x].z = param->map[y][x].z * cos(param->angle * ANGLE) + temp * sin(param->angle * ANGLE);
            }
            if (rotation == 'y')
            {
                temp = param->map[y][x].x;
                param->map[y][x].x = param->map[y][x].x * cos(param->angle * ANGLE) - param->map[y][x].z * sin(param->angle * ANGLE);
                param->map[y][x].z = param->map[y][x].z * cos(param->angle * ANGLE) + temp * sin(param->angle * ANGLE);
            }
            if (rotation == 'z')
            {
                temp = param->map[y][x].x;
                param->map[y][x].x = param->map[y][x].x * cos(param->angle * ANGLE) - param->map[y][x].y * sin(param->angle * ANGLE);
                param->map[y][x].y = param->map[y][x].y * cos(param->angle * ANGLE) + temp * sin(param->angle * ANGLE);
            }
        }
    }
    ft_bresenham_map(param->map, param);
}

/* void    ft_2d_rotation_matrix(t_arg *param)
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
                projection[y][x].x = cos(param->param->angle) * param->map[y][x].x - sin(param->param->angle) * param->map[y][x].y;
                projection[y][x].y = sin(param->param->angle) * param->map[y][x].x + cos(param->param->angle) * param->map[y][x].y;
            }
        }
        ft_bresenham_map(projection, param);
        free(projection);
} */

/* static k_point     **ft_allocate_projection(size_t rows, size_t columns)
{
    k_point **map;
    int     count;

    count = -1;
    map = (k_point**)malloc(sizeof(k_point*) * rows);
    while(++count < (int)rows)
        map[count] = (k_point*)malloc(sizeof(k_point) * columns);
    return(map);
} */