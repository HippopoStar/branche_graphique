#include "fdf.h"

void	fdf_draw(t_fdf *win0, t_point **pos)
{
	size_t	i;
	size_t	j;
	t_point	*p;
	t_point	*p_hor;
	t_point	*p_ver;

	i = 0;
	while (i < win0->map_height - 1)
	{
		j = 0;
		while (j < win0->map_width - 1)
		{
			p = &(*(*(pos + i) + j));
			p_hor = &(*(*(pos + i + 1) + j));
			p_ver = &(*(*(pos + i) + j + 1));
			if (fdf_prime_improvement(p, p_hor))
				fdf_bresenham(*p, *p_hor, win0->mlx_ptr, win0->win_ptr);
			if (fdf_prime_improvement(p, p_ver))
				fdf_bresenham(*p, *p_ver, win0->mlx_ptr, win0->win_ptr);
			j++;
		}
		i++;
	}
}

void	fdf_redraw(t_fdf *win0)
{
	mlx_clear_window(win0->mlx_ptr, win0->win_ptr);
	fdf_draw(win0, win0->pos);
	fdf_color_palette(win0->mlx_ptr, win0->win_ptr, CP_X0, CP_Y0);
}
