/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:58:55 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 03:39:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init_struct(int width, int height, char *title, t_fdf **win0)
{
	if (!((*win0) = (t_fdf *)malloc(sizeof(t_fdf))))
		fdf_error_code("fdf_init_struct");
	if (!((*win0)->mlx_ptr = mlx_init()))
		fdf_error_code("fdf_init_struct");
	if (!((*win0)->win_ptr =\
				mlx_new_window((*win0)->mlx_ptr, width, height, title)))
		fdf_error_code("fdf_init_struct");
	(*win0)->ori_abs = ORI_ABS;
	(*win0)->ori_ord = ORI_ORD;
	(*win0)->depla_x = 0;
	(*win0)->depla_y = 0;
	(*win0)->zoom = FDF_DEFAULT_ZOOM;
	(*win0)->intensity = FDF_DEFAULT_INTENSITY;
	(*win0)->color = ft_melt_colors(0, 255, 0);
	ft_break_color_down(&((*win0)->r0), &((*win0)->g0),\
			&((*win0)->b0), (*win0)->color);
}
