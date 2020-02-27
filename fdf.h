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

# include "/usr/local/include/mlx.h"
# include <unistd.h>

typedef struct		s_list
{
	int				y;
	int				x;
	int				z;
	double			colour;
}					t_list;

#endif
