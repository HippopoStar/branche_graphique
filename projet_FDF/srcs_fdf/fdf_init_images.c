/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:15:38 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 03:16:41 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_put_px_into_img(t_mlx_img *pic, int x, int y, int color)
{
	char	*px;
	int		r;
	int		g;
	int		b;

	if ((0 <= x && x < pic->width) && (0 <= y && y < pic->height))
	{
		px = pic->img_str + (4 * y * pic->width) + (4 * x);
		ft_break_color_down(&r, &g, &b, color);
		*(px + 2) = (char)r;
		*(px + 1) = (char)g;
		*(px + 0) = (char)b;
	}
}

void	fdf_clear_img(t_mlx_img *pic)
{
	size_t	i;

	i = 0;
	while (i < (size_t)(4 * pic->height * pic->width))
	{
		*(pic->img_str + i) = '\0';
		i++;
	}
}

void	fdf_init_img_fdf(t_fdf *win0)
{
	t_mlx_img	*ptr;

	if (!(win0->mlx_img_fdf = (t_mlx_img *)malloc(sizeof(t_mlx_img))))
		fdf_error_code("fdf_init_img_fdf");
	ptr = win0->mlx_img_fdf;
	if (!(ptr->img_ptr = mlx_new_image(win0->mlx_ptr, WIN0_SX, WIN0_SY)))
		fdf_error_code("fdf_init_img_fdf");
	if (!(ptr->img_str = mlx_get_data_addr(ptr->img_ptr, &(ptr->bpp),\
					&(ptr->s_l), &(ptr->endian))))
		fdf_error_code("fdf_init_img_fdf");
	ptr->width = WIN0_SX;
	ptr->height = WIN0_SY;
	fdf_clear_img(ptr);
}

void	fdf_init_images(t_fdf *win0)
{
	t_mlx_img	*ptr;

	fdf_init_img_fdf(win0);
	if (!(win0->mlx_img_cp = (t_mlx_img *)malloc(sizeof(t_mlx_img))))
		fdf_error_code("fdf_init_images");
	ptr = win0->mlx_img_cp;
	if (!(ptr->img_ptr = mlx_new_image(win0->mlx_ptr, 128, 128)))
		fdf_error_code("fdf_init_images");
	if (!(ptr->img_str = mlx_get_data_addr(ptr->img_ptr, &(ptr->bpp),\
					&(ptr->s_l), &(ptr->endian))))
		fdf_error_code("fdf_init_images");
	ptr->width = 128;
	ptr->height = 128;
}
