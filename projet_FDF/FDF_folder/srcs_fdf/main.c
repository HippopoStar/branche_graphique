#include "fdf.h"

int	fdf_deal_key(int key, void *param)
{
	void	**display;

	display = (void **)param;
	if (key == XK_Escape)
	{
		mlx_destroy_window(*(display + 0), *(display + 1));
		free(display);
		exit (0);
	}
	if ('a' <= key && key <= 'z')
	{
		mlx_pixel_put(*(display + 0), *(display + 1), (0 + key), (500 - key), 0xFFFFFF);
		ft_putchar(key);
		ft_putchar('\n');
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

/*
** *(display + 0) = mlx_ptr
** *(display + 1) = win_ptr
*/

void	fdf(int argc, char **argv)
{
	void	**display;

	if (!(display = (void **)malloc(2 * sizeof(void *))))
		exit (0);
	*(display + 0) = mlx_init();
	*(display + 1) = mlx_new_window(*(display + 0), 500, 500, "FDF");
	aux_fdf(argc, argv, *(display + 0), *(display + 1));
	mlx_key_hook(*(display + 1), fdf_deal_key, (void *)display);
	mlx_loop(*(display + 0));
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
