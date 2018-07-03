#include "fdf.h"

int	fdf_deal_key(int key, void *param)
{
	ft_putnbr_base(key, "0123456789ABCDEF");
	if (key == MLX_Escape)
	{
		exit (0);
	}
	else
	{
		fdf_intensity(key, (t_fdf *)param);
		fdf_reset(key, (t_fdf *)param);
	}
	return (0);
}
