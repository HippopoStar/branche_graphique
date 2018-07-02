#include "fdf.h"

void	fdf_draw_two_last_lines(t_fdf *win0, t_point **pos, size_t width, size_t height)
{
	size_t	i;
	t_point	*p0;
	t_point	*p1;

	i = 0;
	while (i < height)
	{
		p1 = &(*(*(pos + i + 1) + width));
		p0 = &(*(*(pos + i) + width));
		fdf_bresenham(p0, p1, win0->mlx_ptr, win0->win_ptr);
		i++;
	}
	i = 0;
	while (i < width)
	{
		p0 = &(*(*(pos + height) + i));
		p1 = &(*(*(pos + height) + i + 1));
		fdf_bresenham(p0, p1, win0->mlx_ptr, win0->win_ptr);
		i++;
	}
}

void	fdf_aux_draw(t_point *p, t_point *p_hor, t_point *p_ver, t_fdf *win0)
{
	fdf_bresenham(p, p_hor, win0->mlx_ptr, win0->win_ptr);
	fdf_bresenham(p, p_ver, win0->mlx_ptr, win0->win_ptr);
}

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
			fdf_aux_draw(p, p_hor, p_ver, win0);
			j++;
		}
		i++;
	}
	fdf_draw_two_last_lines(win0, pos, win0->map_width - 1, win0->map_height - 1);
}

void	fdf_redraw(t_fdf *win0)
{
	mlx_clear_window(win0->mlx_ptr, win0->win_ptr);
	fdf_draw(win0, win0->pos);
	fdf_color_palette(win0->mlx_ptr, win0->win_ptr, CP_X0, CP_Y0);
}

void	fdf_redraw_full(t_fdf *win0)
{
	fdf_projection(win0, fdf_iso);
	fdf_redraw(win0);
}
