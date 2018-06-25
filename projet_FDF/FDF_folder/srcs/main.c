#include "fdf.h"

#include <stdlib.h> //ATTENTION : 'atoi'

void	aux_fdf(int argc, char **argv, void *mlx_ptr, void *win_ptr)
{
	t_point	a;
	t_point	b;

	(void)argc;
	(void)argv;
	a.x = atoi(*(argv + 0)); //ATTENTION : 'atoi'
	a.y = atoi(*(argv + 1)); //ATTENTION : 'atoi'
	b.x = atoi(*(argv + 2)); //ATTENTION : 'atoi'
	b.y = atoi(*(argv + 3)); //ATTENTION : 'atoi'
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
//		usage();
	}
	else
	{
		fdf(argc - 1, argv + 1);
	}
	return (0);
}
