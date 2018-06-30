#include "fdf.h"

int	fdf_deal_key(int key, void *param)
{
	t_fdf	*win0;

	win0 = (t_fdf *)param;
	if (key == XK_Escape)
	{
		mlx_destroy_window(win0->mlx_ptr, win0->win_ptr);
		free(win0);
		exit (0);
	}
	if ('a' <= key && key <= 'z')
	{
		mlx_pixel_put(win0->mlx_ptr, win0->win_ptr, (0 + key), (500 - key), ft_melt_colors(0, 255, 50));
		ft_putchar(key);
		ft_putchar(' ');
	}
	return (0);
}

void	fdf(char *file_name)
{
	t_fdf	*win0;

	win0 = (t_fdf *)malloc(sizeof(t_fdf));
	fdf_init_struct(500, 500, "FDF", &win0);
	fdf_init_map(file_name, win0);
	fdf_show_map(win0);
	fdf_init_pos_map(win0);
	fdf_color_pos(win0);
	fdf_projection(win0, fdf_iso);
	fdf_draw(win0, win0->pos);
	mlx_key_hook(win0->win_ptr, fdf_deal_key, (void *)win0);
	mlx_loop(win0->mlx_ptr);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		fdf_usage();
	}
	else
	{
		fdf(*(argv + 1));
	}
	return (0);
}
