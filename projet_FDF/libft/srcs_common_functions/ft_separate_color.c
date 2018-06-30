#include "libft.h"

void	ft_separate_color(int *red, int *green, int *blue, int color)
{
	color = color % 0xFFFFFF;
	*red = color / 0x00FFFF;
	color = color % 0x00FFFF;
	*green = color / 0x0000FF;
	color = color % 0x0000FF;
	*blue = color;
}
