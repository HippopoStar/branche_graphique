/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_allocate_to_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:54:31 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 20:06:27 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_allocate_to_pos(t_fdf *win0)
{
	size_t	i;

	if (!(win0->pos = (t_point **)malloc(win0->map_height * sizeof(t_point *))))
	{
		fdf_error_code("fdf_init_pos_map");
	}
	i = 0;
	while (i < win0->map_height)
	{
		if (!(*(win0->pos + i) =\
					(t_point *)malloc(win0->map_width * sizeof(t_point))))
		{
			fdf_error_code("fdf_init_pos_map");
		}
		i++;
	}
}
