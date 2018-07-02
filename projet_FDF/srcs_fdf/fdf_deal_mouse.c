#include "fdf.h"

int	fdf_deal_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	ft_putnbr_base(button, "0123456789ABCDEF");
	fdf_pick_a_color(button, mouse_x, mouse_y, (t_fdf *)param);
	fdf_zoom(button, (t_fdf *)param);
	fdf_deplace(button, mouse_x, mouse_y, (t_fdf *)param);
	return (0);
}
