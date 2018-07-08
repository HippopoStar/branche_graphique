/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:59:57 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 03:40:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_reset(int key, t_fdf *win0)
{
	if (key == MLX_R)
	{
		if (!(win0->ori_abs == ORI_ABS && win0->ori_ord == ORI_ORD))
		{
			win0->ori_abs = ORI_ABS;
			win0->ori_ord = ORI_ORD;
			fdf_redraw_full(win0);
		}
		else if (win0->intensity != FDF_DEFAULT_INTENSITY)
		{
			win0->intensity = FDF_DEFAULT_INTENSITY;
			fdf_redraw_full(win0);
		}
		else if (win0->zoom != FDF_DEFAULT_ZOOM)
		{
			win0->zoom = FDF_DEFAULT_ZOOM;
			fdf_redraw_full(win0);
		}
		return (1);
	}
	return (0);
}
