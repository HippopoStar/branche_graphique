#include "fdf.h"

void	fdf_zoom(int button, t_fdf *win0)
{
	if (button == MLX_Pointer_Button4 || button == MLX_Pointer_Button5)
	{
		(button == MLX_Pointer_Button4) ? (win0->zoom)++ : (win0->zoom)--;
		fdf_redraw_full(win0);
	}
}
