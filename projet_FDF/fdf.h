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
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define XK_Escape	0xFF1B

typedef struct		s_point
{
	int				x;
	int				y;
}			t_point;

typedef struct		s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	int				ori_abs;
	int				ori_ord;
	int				**map;
	size_t				map_width;
	size_t				map_heigth;
	int				zoom;
	int				intensity;
	int				color;
}			t_fdf;

typedef struct		s_fdf_line
{
	char				*str;
	struct s_fdf_line		*next;
}			t_fdf_line;

void	fdf_usage(void);
void	fdf_error_code(char *error_message);
void	fdf_bresenham(t_point a, t_point b, void *mlx_ptr, void *win_ptr);
void	fdf_init_struct(int width, int height, char *title, t_fdf **win0);
void	fdf_init_map(char *file_name, t_fdf *win0);
int	fdf_deal_key(int key, void *param);

#endif
