#include "fdf.h"

void	fdf_draw(t_fdf *win0, t_point **pos)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < win0->map_height - 1)
	{
		j = 0;
		while (j < win0->map_width - 1)
		{
			fdf_bresenham(*(*(pos + i) + j), *(*(pos + i + 1) + j), win0->mlx_ptr, win0->win_ptr);
			fdf_bresenham(*(*(pos + i) + j), *(*(pos + i) + j + 1), win0->mlx_ptr, win0->win_ptr);
			j++;
		}
		i++;
	}
}
