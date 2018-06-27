#include "fdf.h"

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
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF");
	aux_fdf(argc, argv, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
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
