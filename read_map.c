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

static t_point     **ft_make_map(int fd, t_point **map, int rows, int columns)
{
    int         countrows;
    int         countcolumns;
    char        *line;
    char        **coords;

    printf("%d %d\n", rows, columns);
    countrows = -1;
    while (++countrows < (int)rows)
    {
        countcolumns = -1;
        get_next_line(fd, &line);
        coords = ft_strsplit(line, ' ');
        while (++countcolumns < (int)columns)
        {
            map[countrows][countcolumns].x = countcolumns - (columns / 2); 
            map[countrows][countcolumns].y = countrows - (rows / 2);
            map[countrows][countcolumns].z = ft_atoi(coords[countcolumns]);
            free(coords[countcolumns]);
        }
        free(line);
        free(coords);
    }
    return(map);
}

static t_point     **ft_allocate_map(int rows, int columns)
{
    t_point **map;
    int     count;

    count = -1;
    map = (t_point**)malloc(sizeof(t_point*) * rows);
    while(++count < (int)rows)
        map[count] = (t_point*)malloc(sizeof(t_point) * columns);
    return(map);
}

void     ft_read_map(char *file_name, t_arg **param)
{
    int     fd;
    char    *line;
    int  rows;
    int  columns;
    
    rows = 0;
    fd = open(file_name, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        rows++;
        free(line);
    }
    columns = ft_wordcount(line, ' ');
    close(fd);
    (*param)->map = ft_allocate_map(rows, columns);
    
    fd = open(file_name, O_RDONLY);
    (*param)->map = ft_make_map(fd, (*param)->map, rows, columns);
    close(fd);
    (*param)->rows = rows;
    (*param)->columns = columns;
}