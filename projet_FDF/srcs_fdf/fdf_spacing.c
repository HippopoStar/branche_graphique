/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_spacing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 03:18:29 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/09 03:28:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_spacing(int key, t_fdf *win0)
{
	if (key == MLX_UP
		|| (key == MLX_DOWN && win0->spacing > 1))
	{
		(key == MLX_UP) ? (win0->spacing)++ : (win0->spacing)--;
		(win0->optimize == 0) ? fdf_redraw_full(win0) : fdf_img_redraw_full(win0);
		return (1);
	}
	return (0);
}
