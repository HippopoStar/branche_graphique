/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:17:07 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/19 23:29:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define XK_Escape	0xFF1B

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void	fdf_usage(void);
void	fdf_bresenham(t_point a, t_point b, void *mlx_ptr, void *win_ptr);

#endif
