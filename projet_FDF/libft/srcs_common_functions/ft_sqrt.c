#include "libft.h"

/*
** On a :
** 46340^(2)	= 2 147 395 600
** 46341^(2)	= 2 147 488 281
*/

int	ft_sqrt(int n)
{
	int	i;
	int	i_square;

	if (n <= 0)
	{
		return (0);
	}
	else if (2147395600 <= n)
	{
		return (46340);
	}
	else
	{
		i = 1;
		while ((i_square = i * i) <= n)
		{
			i++;
		}
		return (i - 1);
	}
}
