#include "fdf.h"

int	fdf_deal_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	fdf_pick_a_color(button, mouse_x, mouse_y, (t_fdf *)param);
	return (0);
}
