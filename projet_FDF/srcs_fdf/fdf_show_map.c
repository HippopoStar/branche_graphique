#include "fdf.h"

void	fdf_show_map(t_fdf *win0)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < win0->map_height)
	{
		j = 0;
		while (j < win0->map_width)
		{
			ft_putnbr(*(*(win0->map + i) + j));
			ft_putchar('\t');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
