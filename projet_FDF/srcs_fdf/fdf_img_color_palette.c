/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_color_palette.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:19:55 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 03:19:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_img_color_palette(t_mlx_img *pic)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < 128)
	{
		y = 0;
		while (y < 128)
		{
			color = ft_melt_colors(255 - (2 * x), 2 * y, 2 * x);
			fdf_put_px_into_img(pic, x, y, color);
			y++;
		}
		x++;
	}
}
