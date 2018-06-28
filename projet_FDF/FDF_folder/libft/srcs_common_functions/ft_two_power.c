#include "libft.h"

int		ft_two_power(int n);
{
	int	i;
	int	nb;

	nb = 1;
	i = 0;
	while (i < n)
	{
		nb = 2 * nb;
		i++;
	}
	return (nb);
}
