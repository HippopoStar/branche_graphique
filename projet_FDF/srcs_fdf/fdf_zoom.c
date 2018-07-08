/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:00:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 03:30:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_zoom(int button, t_fdf *win0)
{
	if (button == MLX_POINTER_BUTTON4
		|| (button == MLX_POINTER_BUTTON5 && win0->zoom > 1))
	{
		(button == MLX_POINTER_BUTTON4) ? (win0->zoom)++ : (win0->zoom)--;
		fdf_redraw_full(win0);
		return (1);
	}
	return (0);
}
