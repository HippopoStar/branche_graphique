#include "fdf.h"

int	fdf_gradation(t_point cur, t_point des, int cur_dist, int tot_dist)
{
	int	color;
	int	red_diff;
	int	green_diff;
	int	blue_diff;

	red_diff = des.r - cur.r;
	green_diff = des.g - cur.g;
	blue_diff = des.b - cur.b;
	color = 0;
	color = color + (des.r - ((red_diff * cur_dist) / tot_dist)) * 0x010000;
	color = color + (des.g - ((green_diff * cur_dist) / tot_dist)) * 0x000100;
	color = color + (des.b - ((blue_diff * cur_dist) / tot_dist));
	return (color);
}
