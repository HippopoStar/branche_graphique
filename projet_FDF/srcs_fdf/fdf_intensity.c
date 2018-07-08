/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_intensity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:59:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 03:30:56 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_intensity(int key, t_fdf *win0)
{
	if (key == MLX_U || key == MLX_D)
	{
		(key == MLX_U) ? (win0->intensity)++ : (win0->intensity)--;
		fdf_redraw_full(win0);
		return (1);
	}
	return (0);
}
