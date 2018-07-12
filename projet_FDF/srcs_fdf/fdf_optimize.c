/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_optimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:02:51 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 04:20:07 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_optimize(int key, t_fdf *win0)
{
	if (key == MLX_I)
	{
		if (win0->optimize == 0)
		{
			win0->optimize = 1;
			fdf_img_redraw(win0);
		}
		else
		{
			win0->optimize = 0;
			fdf_redraw(win0);
		}
		return (1);
	}
	return (0);
}
