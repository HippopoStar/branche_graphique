#include "fdf.h"

void	fdf_aux_color_pos(t_point *p, int val, t_fdf *win0)
{
	if (val > 0)
	{
		(*p).r = 255 - ((255 - win0->r0) * val) / win0->max_val;
		(*p).g = 255 - ((255 - win0->g0) * val) / win0->max_val;
		(*p).b = 255 - ((255 - win0->b0) * val) / win0->max_val;
	}
	else
	{
		(*p).r = 255;
		(*p).g = 255;
		(*p).b = 255;
	}
}

void	fdf_color_pos(t_fdf *win0)
{
	t_point	*p;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < win0->map_height)
	{
		j = 0;
		while (j < win0->map_width)
		{
			p = &(*(*(win0->pos + i) + j));
			fdf_aux_color_pos(p, *(*(win0->map + i) + j), win0);
			j++;
		}
		i++;
	}
}
