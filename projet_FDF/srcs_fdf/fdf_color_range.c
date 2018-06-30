#include "fdf.h"

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
