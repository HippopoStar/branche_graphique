/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:59:42 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/09 03:44:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_quasi_iso(t_point *pos, size_t i, size_t j, t_fdf *win0)
{
	pos->x = win0->ori_abs;
	pos->x = pos->x - ((int)i * ((win0->zoom > 1) ? win0->zoom : 1));
	pos->x = pos->x + ((int)j * ((win0->zoom > 1) ? win0->zoom : 1));
	pos->x = pos->x - (win0->intensity * *(*(win0->map + i) + j));
	pos->y = win0->ori_ord;
	pos->y = pos->y + ((int)i * ((win0->zoom > 1) ? win0->zoom : 1));
	pos->y = pos->y + ((int)j * ((win0->zoom > 1) ? win0->zoom : 1));
	pos->y = pos->y - (3 * win0->intensity * *(*(win0->map + i) + j));
}

void	fdf_iso(t_point *pos, size_t i, size_t j, t_fdf *win0)
{
	pos->x = 0;
	pos->x = pos->x - (7 * (int)i);
	pos->x = pos->x + (7 * (int)j);
	pos->x = pos->x * win0->spacing;
	fdf_apply_zoom(&(pos->x), win0);
	pos->x = pos->x + win0->ori_abs;
	pos->y = 0;
	pos->y = pos->y + (4 * (int)i);
	pos->y = pos->y + (4 * (int)j);
	pos->y = pos->y * win0->spacing;
	pos->y = pos->y - (8 * *(*(win0->map + i) + j) * win0->intensity);
	fdf_apply_zoom(&(pos->y), win0);
	pos->y = pos->y + win0->ori_ord;
}

void	fdf_projection(t_fdf *win0,\
								void (*f)(t_point *, size_t, size_t, t_fdf *))
{
	size_t	i;
	size_t	j;
	t_point	*p;

	i = 0;
	while (i < win0->map_height)
	{
		j = 0;
		while (j < win0->map_width)
		{
			p = &(*(*(win0->pos + i) + j));
			f(p, i, j, win0);
			fdf_assign_a_prime_number(p);
			j++;
		}
		i++;
	}
}
