#include "fdf.h"

int	fdf_deal_key(int key, void *param)
{
	t_fdf	*win0;

	win0 = (t_fdf *)param;
	if (key == MLX_Escape)
	{
		exit (0);
	}
	else if ('a' <= key && key <= 'z')
	{
		mlx_pixel_put(win0->mlx_ptr, win0->win_ptr, (0 + key), (500 - key), ft_melt_colors(0, 255, 50));
		ft_putchar(key);
		ft_putchar(' ');
	}
	return (0);
}
