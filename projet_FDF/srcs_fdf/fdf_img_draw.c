/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:18:44 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 03:18:52 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_img_build_two_last_lines(t_fdf *win0, t_point **pos,
													size_t width, size_t height)
{
	size_t	i;
	t_point	*p0;
	t_point	*p1;

	i = 0;
	while (i < height)
	{
		p1 = &(*(*(pos + i + 1) + width));
		p0 = &(*(*(pos + i) + width));
		fdf_img_imp_bresenham(p0, p1, win0->mlx_img_fdf);
		i++;
	}
	i = 0;
	while (i < width)
	{
		p0 = &(*(*(pos + height) + i));
		p1 = &(*(*(pos + height) + i + 1));
		fdf_img_imp_bresenham(p0, p1, win0->mlx_img_fdf);
		i++;
	}
}

void	fdf_img_build(t_fdf *win0, t_point **pos)
{
	size_t	i;
	size_t	j;
	t_point	*p;
	t_point	*p_hor;
	t_point	*p_ver;

	i = 0;
	while (i < win0->map_height - 1)
	{
		j = 0;
		while (j < win0->map_width - 1)
		{
			p = &(*(*(pos + i) + j));
			p_hor = &(*(*(pos + i + 1) + j));
			p_ver = &(*(*(pos + i) + j + 1));
			fdf_img_imp_bresenham(p, p_hor, win0->mlx_img_fdf);
			fdf_img_imp_bresenham(p, p_ver, win0->mlx_img_fdf);
			j++;
		}
		i++;
	}
	fdf_img_build_two_last_lines(win0, pos,\
			win0->map_width - 1, win0->map_height - 1);
}

void	fdf_img_draw(t_fdf *win0, t_point **pos)
{
	fdf_img_build(win0, pos);
	mlx_put_image_to_window(win0->mlx_ptr, win0->win_ptr,\
			(win0->mlx_img_fdf)->img_ptr, 0, 0);
	mlx_put_image_to_window(win0->mlx_ptr, win0->win_ptr,\
			(win0->mlx_img_cp)->img_ptr, CP_X0, CP_Y0);
	fdf_display_parameters(win0);
}

void	fdf_img_redraw(t_fdf *win0)
{
	fdf_clear_img(win0->mlx_img_fdf);
	fdf_img_build(win0, win0->pos);
	mlx_clear_window(win0->mlx_ptr, win0->win_ptr);
	mlx_put_image_to_window(win0->mlx_ptr, win0->win_ptr,\
			(win0->mlx_img_fdf)->img_ptr, 0, 0);
	mlx_put_image_to_window(win0->mlx_ptr, win0->win_ptr,\
			(win0->mlx_img_cp)->img_ptr, CP_X0, CP_Y0);
	fdf_display_parameters(win0);
}

void	fdf_img_redraw_full(t_fdf *win0)
{
	fdf_projection(win0, fdf_iso);
	fdf_img_redraw(win0);
}
