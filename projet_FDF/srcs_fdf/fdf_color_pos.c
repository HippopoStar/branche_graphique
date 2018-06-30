#include "fdf.h"

void	fdf_color_pos(t_fdf *win0)
{
	int	r0;
	int	g0;
	int	b0;
	size_t	i;
	size_t	j;

	ft_separate_color(&r0, &g0, &b0, win0->color);
	i = 0;
	while (i < win0->map_height)
	{
		j = 0;
		while (j < win0->map_width)
		{
			(*(*(win0->pos + i) + j)).r = 255 - ((*(*(win0->map + i) + j) / win0->max_val) * r0);
			(*(*(win0->pos + i) + j)).g = 255 - ((*(*(win0->map + i) + j) / win0->max_val) * g0);
			(*(*(win0->pos + i) + j)).b = 255 - ((*(*(win0->map + i) + j) / win0->max_val) * b0);
			j++;
		}
		i++;
	}
}
