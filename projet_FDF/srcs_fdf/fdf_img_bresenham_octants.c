/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_bresenham_octants.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:19:27 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 03:19:30 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fdf_bresenham_first_octant
**		|
**		|
**		|		x
** _____________|_____________
**		|
**		|
**		|
**		|
*/

void	fdf_img_bresenham_1st_octant(t_point a, t_point b, t_mlx_img *pic)
{
	int	dx;
	int	dy;
	int	e;

	e = b.x - a.x;
	dx = 2 * e;
	dy = 2 * (b.y - a.y);
	while (a.x < b.x)
	{
		fdf_put_px_into_img(pic, a.x, a.y,\
				fdf_gradation(a, b, b.x - a.x, dx / 2));
		a.x = a.x + 1;
		e = e - dy;
		if (e < 0)
		{
			a.y = a.y + 1;
			e = e + dx;
		}
	}
}

/*
** fdf_bresenham_2nd_octant
**		| x
**		|
**		|
** _____________|_____________
**		|
**		|
**		|
**		|
*/

void	fdf_img_bresenham_2nd_octant(t_point a, t_point b, t_mlx_img *pic)
{
	int	dx;
	int	dy;
	int	e;

	e = b.y - a.y;
	dx = 2 * (b.x - a.x);
	dy = 2 * e;
	while (a.y < b.y)
	{
		fdf_put_px_into_img(pic, a.x, a.y,\
				fdf_gradation(a, b, b.y - a.y, dy / 2));
		a.y = a.y + 1;
		e = e - dx;
		if (e < 0)
		{
			a.x = a.x + 1;
			e = e + dy;
		}
	}
}

/*
** fdf_bresenham_8th_octant
**		|
**		|
**		|
** _____________|_____________
**		|		x
**		|
**		|
**		|
*/

void	fdf_img_bresenham_8th_octant(t_point a, t_point b, t_mlx_img *pic)
{
	int	dx;
	int	dy;
	int	e;

	e = b.x - a.x;
	dx = 2 * e;
	dy = 2 * (b.y - a.y);
	while (a.x < b.x)
	{
		fdf_put_px_into_img(pic, a.x, a.y,\
				fdf_gradation(a, b, b.x - a.x, dx / 2));
		a.x = a.x + 1;
		e = e + dy;
		if (e < 0)
		{
			a.y = a.y - 1;
			e = e + dx;
		}
	}
}

/*
** fdf_bresenham_7th_octant
**		|
**		|
**		|
** _____________|_____________
**		|
**		|
**		|
**		| x
*/

void	fdf_img_bresenham_7th_octant(t_point a, t_point b, t_mlx_img *pic)
{
	int	dx;
	int	dy;
	int	e;

	e = b.y - a.y;
	dx = 2 * (b.x - a.x);
	dy = 2 * e;
	while (a.y > b.y)
	{
		fdf_put_px_into_img(pic, a.x, a.y,\
				fdf_gradation(a, b, b.y - a.y, dy / 2));
		a.y = a.y - 1;
		e = e + dx;
		if (e > 0)
		{
			a.x = a.x + 1;
			e = e + dy;
		}
	}
}
