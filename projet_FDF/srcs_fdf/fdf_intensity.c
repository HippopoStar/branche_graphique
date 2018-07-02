#include "fdf.h"

void	fdf_intensity(int key, t_fdf *win0)
{
	if (key == MLX_U || key == MLX_D)
	{
		(key == MLX_U) ? (win0->intensity)++ : (win0->intensity)--;
		fdf_redraw_full(win0);
	}
}
