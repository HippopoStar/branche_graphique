#include "fdf.h"

void	fdf_iso(t_point *pos, size_t i, size_t j, t_fdf *win0)
{
	pos->x = win0->ori_abs;
	pos->x = pos->x - ((int)i * win0->zoom);
	pos->x = pos->x + ((int)j * win0->zoom);
	pos->x = pos->x - (win0->intensity * *(*(win0->map + i) + j));
	pos->y = win0->ori_ord;
	pos->y = pos->y + ((int)i * win0->zoom);
	pos->y = pos->y + ((int)j * win0->zoom);
	pos->y = pos->y - (3 * win0->intensity * *(*(win0->map + i) + j));
}

void	fdf_projection(t_fdf *win0, void (*f)(t_point *, size_t, size_t, t_fdf *))
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
