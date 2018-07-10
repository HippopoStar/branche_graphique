/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:54:46 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 20:13:52 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Lors de l'appel de 'fdf_aux_bresenham', on a dors et deja
** l'assurance d'avoir [a, b] non vertical et {a} a gauche de {b}
*/

void	fdf_img_aux_bresenham(t_point a, t_point b, t_mlx_img *pic)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dy > 0)
	{
		(dx >= dy) ? fdf_img_bresenham_1st_octant(a, b, pic)
					: fdf_img_bresenham_2nd_octant(a, b, pic);
	}
	else if (dy < 0)
	{
		(dx >= -dy) ? fdf_img_bresenham_8th_octant(a, b, pic)
					: fdf_img_bresenham_7th_octant(a, b, pic);
	}
	else
	{
		while (a.x < b.x)
		{
			fdf_put_px_into_img(pic, a.x, a.y,\
					fdf_gradation(a, b, b.x - a.x, dx));
			a.x = a.x + 1;
		}
	}
}

/*
** La fonction 'fdf_bresenham', selon les caracteristiques du segment [a, b] :
** - ne fait rien si {a} et {b} confondus
** - trace [a, b] si a->b vertical oriente vers le bas
** - se rappelle elle-meme en intervertissant {a} et {b} si a->b vertical
**   oriente vers le haut
** - appelle 'fdf_aux_bresenham' si a->b non vertical avec a->b oriente vers
**   la droite
** - appelle 'fdf_aux_bresenham' en intervertissant {a} et {b} si a->b
**   non vertical oriente vers la gauche
*/

void	fdf_img_bresenham(t_point a, t_point b, t_mlx_img *pic)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx != 0)
	{
		(dx > 0) ? fdf_img_aux_bresenham(a, b, pic)
			: fdf_img_aux_bresenham(b, a, pic);
	}
	else
	{
		if (dy > 0)
		{
			while (a.y < b.y)
			{
				fdf_put_px_into_img(pic, a.x, a.y, 0xFFFFFF);
				a.y = a.y + 1;
			}
		}
		else if (dy < 0)
		{
			fdf_img_bresenham(b, a, pic);
		}
	}
}

void	fdf_img_imp_bresenham(t_point *a, t_point *b, t_mlx_img *pic)
{
	if (fdf_prime_improvement(a, b))
	{
		fdf_img_bresenham(*a, *b, pic);
	}
}
