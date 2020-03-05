/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:10:01 by thalme            #+#    #+#             */
/*   Updated: 2020/03/05 15:10:02 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_point     *make_map(int fd, t_point *map, size_t rows, size_t columns)
{
    size_t      countrows;
    size_t      countcolumns;
    size_t      count;
    char        *line;
    char        **coords;

    ft_putnbr(rows);
        ft_putnbr(columns);

    count = 0;
    countrows = -1;
    while (++countrows < rows)
    {
        countcolumns = -1;
        ft_putnbr(countrows);
        ft_putendl("a");
        ft_putendl("a");

        get_next_line(fd, &line);
        coords = ft_strsplit(line, ' ');
        while (++countcolumns < columns)
        {
            ft_putnbr(countcolumns);
            ft_putendl("b");
            map[count].x = countcolumns; 
            map[count].y = countrows;
            map[count].z = ft_atoi(coords[countcolumns]);
            
        }
        free(line);
        free(coords);
        
    }
    
    return(map);
}

t_point     *read_map(char *file_name)
{
    int     fd;
    t_point *map;
    char    *line;
    size_t  rows;
    size_t  columns;
    
    rows = 0;
    fd = open(file_name, O_RDONLY);
    while (get_next_line(fd, &line))
        rows++;
    columns = ft_wordcount(line, ' ');
    close(fd);
    map = (t_point*)malloc(sizeof(t_point) * rows * columns + 1);
    fd = open(file_name, O_RDONLY);
    map = make_map(fd, map, rows, columns);
    close(fd);
    return (map);
}