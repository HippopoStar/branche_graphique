#include "libft.h"

void	ft_break_color_down(int *red, int *green, int *blue, int color)
{
	color = color % 0x1000000;
	*red = color / 0x010000;
	color = color % 0x010000;
	*green = color / 0x000100;
	color = color % 0x000100;
	*blue = color;
}
