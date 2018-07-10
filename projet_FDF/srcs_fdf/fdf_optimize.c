#include "fdf.h"

int	fdf_optimize(int key, t_fdf *win0)
{
	if (key == MLX_I)
	{
		win0->optimize = ((win0->optimize == 1) ? 0 : 1);
		return (1);
	}
	return (0);
}
