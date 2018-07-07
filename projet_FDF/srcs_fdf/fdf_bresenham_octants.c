/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_octants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:55:00 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 20:18:37 by lcabanes         ###   ########.fr       */
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

void	fdf_bresenham_1st_octant(t_point a, t_point b,\
												void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	e;

	e = b.x - a.x;
	dx = 2 * e;
	dy = 2 * (b.y - a.y);
	while (a.x < b.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y,\
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

void	fdf_bresenham_2nd_octant(t_point a, t_point b,\
												void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	e;

	e = b.y - a.y;
	dx = 2 * (b.x - a.x);
	dy = 2 * e;
	while (a.y < b.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y,\
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

void	fdf_bresenham_8th_octant(t_point a, t_point b,\
												void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	e;

	e = b.x - a.x;
	dx = 2 * e;
	dy = 2 * (b.y - a.y);
	while (a.x < b.x)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y,\
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

void	fdf_bresenham_7th_octant(t_point a, t_point b,\
												void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	e;

	e = b.y - a.y;
	dx = 2 * (b.x - a.x);
	dy = 2 * e;
	while (a.y > b.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y,\
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
