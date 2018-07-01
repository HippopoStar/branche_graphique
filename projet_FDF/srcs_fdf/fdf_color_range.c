#include "fdf.h"

void	fdf_redraw_color(int x_val, int y_val, t_fdf *win0)
{
	win0->color = ft_melt_colors(255- (2 * x_val), 2 * y_val, 2 * x_val);
	ft_break_color_down(&(win0->r0), &(win0->g0), &(win0->b0), win0->color);
	fdf_color_pos(win0);
	fdf_draw(win0, win0->pos);
}

int		fdf_pick_a_color(int m_button, int m_x, int m_y, t_fdf *win0)
{
	if (m_button == MLX_Pointer_Button1)
	{
		if ((4 < m_x && m_x < 132) && (4 < m_y && m_y < 132))
		{
			fdf_redraw_color(m_x - 5, m_y - 5, win0);
			return (1);
		}
	}
	return (0);
}

void	fdf_color_range(void *mlx_ptr, void *win_ptr, int x0, int y0)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < 128)
	{
		y = 0;
		while (y < 128)
		{
			color = ft_melt_colors(255 - (2 * x), 2 * y , 2 * x);
			mlx_pixel_put(mlx_ptr, win_ptr, x0 + x, y0 + y, color);
			y++;
		}
		x++;
	}
}
