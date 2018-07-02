#include "fdf.h"

void	fdf_init_struct(int width, int height, char *title, t_fdf **win0)
{
	if (!((*win0) = (t_fdf *)malloc(sizeof(t_fdf))))
		exit (0);
	if (!((*win0)->mlx_ptr = mlx_init()))
		exit (0);
	if (!((*win0)->win_ptr = mlx_new_window((*win0)->mlx_ptr, width, height, title)))
		exit (0);
	(*win0)->ori_abs = 200;
	(*win0)->ori_ord = 30;
	(*win0)->depla_x = 0;
	(*win0)->depla_y = 0;
	(*win0)->zoom = 30;
	(*win0)->intensity = 1;
	(*win0)->color = ft_melt_colors(0, 255, 0);
	ft_break_color_down(&((*win0)->r0), &((*win0)->g0), &((*win0)->b0), (*win0)->color);
}
