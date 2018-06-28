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
		mlx_pixel_put(win0->mlx_ptr, win0->win_ptr, (0 + key), (500 - key), ft_color(0, 255, 50));
		ft_putchar(key);
		ft_putchar(' ');
	}
	return (0);
}

void	aux_fdf(int argc, char **argv, void *mlx_ptr, void *win_ptr)
{
	t_point	a;
	t_point	b;

	(void)argc;
	(void)argv;
	a.x = ft_atoi(*(argv + 0));
	a.y = ft_atoi(*(argv + 1));
	b.x = ft_atoi(*(argv + 2));
	b.y = ft_atoi(*(argv + 3));
	fdf_bresenham(a, b, mlx_ptr, win_ptr);
}

void	fdf(int argc, char **argv)
{
	t_fdf	*win0;

	fdf_init_struct(500, 500, "FDF", &win0);
	aux_fdf(argc, argv, win0->mlx_ptr, win0->win_ptr);
	mlx_key_hook(win0->win_ptr, fdf_deal_key, (void *)win0);
	mlx_loop(win0->mlx_ptr);
}

int		main(int argc, char **argv)
{
	if (argc != 5)
	{
		fdf_usage();
	}
	else
	{
		fdf(argc - 1, argv + 1);
	}
	return (0);
}
