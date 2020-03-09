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
    int      countrows;
    int      countcolumns;
    size_t      count;
    char        *line;
    char        **coords;

    printf("%zu %zu\n", columns, rows);
    count = 0;
    countrows = -1;
    while (++countrows < (int)rows)
    {
        countcolumns = -1;
        get_next_line(fd, &line);
        coords = ft_strsplit(line, ' ');
        while (++countcolumns < (int)columns)
        {
            map[count].x = countcolumns; 
            map[count].y = countrows;
            map[count].z = ft_atoi(coords[countcolumns]);
            count++;
        }
        free(line);
        free(coords);
    }
    countrows = -1;
    count = 0;
     while (++countrows < (int)rows)
    {
        countcolumns = -1;
        get_next_line(fd, &line);
        coords = ft_strsplit(line, ' ');
        while (++countcolumns < (int)columns)
        {
            printf("X %f\tY %f\tZ %f\t\t",map[count].x, map[count].y,  map[count].z);
            count++;
        }
        printf("\n");
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