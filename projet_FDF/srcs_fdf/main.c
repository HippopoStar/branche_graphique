#include "fdf.h"

void	fdf(char *file_name)
{
	t_fdf	*win0;

	win0 = (t_fdf *)malloc(sizeof(t_fdf));
	fdf_init_struct(WIN0_SX, WIN0_SY, WIN0_TITLE, &win0);
	fdf_init_map(file_name, win0);
	fdf_show_map(win0);
	fdf_allocate_to_pos(win0);
	fdf_color_pos(win0);
	fdf_projection(win0, fdf_iso);
	fdf_draw(win0, win0->pos);
	fdf_color_range(win0->mlx_ptr, win0->win_ptr, 5, 5);
	mlx_key_hook(win0->win_ptr, fdf_deal_key, (void *)win0);
	mlx_mouse_hook(win0->win_ptr, fdf_deal_mouse, (void *)win0);
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
