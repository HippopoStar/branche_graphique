/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:55:38 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 19:55:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_cross(int x0, int y0, int color, t_fdf *win0)
{
	int	i;

	i = -CROSS_SIZE;
	while (i <= CROSS_SIZE)
	{
		mlx_pixel_put(win0->mlx_ptr, win0->win_ptr, x0, y0 + i, color);
		mlx_pixel_put(win0->mlx_ptr, win0->win_ptr, x0 + i, y0, color);
		i++;
	}
}
