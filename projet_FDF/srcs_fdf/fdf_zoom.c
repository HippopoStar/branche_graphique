/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:00:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/09 03:37:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_apply_zoom(int *n, t_fdf *win0)
{
	if (win0->zoom > 1)
	{
		*n = *n * win0->zoom;
	}
	else if (win0->zoom < 1)
	{
		*n = *n / -(win0->zoom - 2);
	}
}

int		fdf_zoom(int button, t_fdf *win0)
{
	if (button == MLX_POINTER_BUTTON4
		|| (button == MLX_POINTER_BUTTON5))
	{
		(button == MLX_POINTER_BUTTON4) ? (win0->zoom)++ : (win0->zoom)--;
		(win0->optimize == 0) ? fdf_redraw_full(win0) : fdf_img_redraw_full(win0);
		return (1);
	}
	return (0);
}
