#include "fdf.h"

void	fdf_color_pos(t_fdf *win0)
{
	int	r0;
	int	g0;
	int	b0;
	size_t	i;
	size_t	j;

	ft_break_color_down(&r0, &g0, &b0, win0->color);
	i = 0;
	while (i < win0->map_height)
	{
		j = 0;
		while (j < win0->map_width)
		{
			if (*(*(win0->map + i) + j) > 0)
			{
				(*(*(win0->pos + i) + j)).r = 255 - ((255 - r0) * *(*(win0->map + i) + j)) / win0->max_val;
				(*(*(win0->pos + i) + j)).g = 255 - ((255 - g0) * *(*(win0->map + i) + j)) / win0->max_val;
				(*(*(win0->pos + i) + j)).b = 255 - ((255 - b0) * *(*(win0->map + i) + j)) / win0->max_val;
			}
			else
			{
				(*(*(win0->pos + i) + j)).r = 255;
				(*(*(win0->pos + i) + j)).g = 255;
				(*(*(win0->pos + i) + j)).b = 255;
			}
			j++;
		}
		i++;
	}
}
