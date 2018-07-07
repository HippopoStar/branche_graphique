/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:59:57 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 19:59:58 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_reset(int key, t_fdf *win0)
{
	if (key == MLX_R)
	{
		if (!(win0->ori_abs == ORI_ABS && win0->ori_ord == ORI_ORD))
		{
			win0->ori_abs = ORI_ABS;
			win0->ori_ord = ORI_ORD;
			fdf_redraw_full(win0);
		}
		else if (win0->intensity != 1)
		{
			win0->intensity = 1;
			fdf_redraw_full(win0);
		}
	}
}
