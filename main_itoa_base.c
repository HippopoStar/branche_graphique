#include "libft.h"

int	  main(int argc, char **argv)
{
	if (argc == 5)
	{
		ft_putstr(ft_itoa_base(ft_atoi(*(argv + 1)), *(argv + 2), (size_t)ft_atoi(*(argv + 3)), (size_t)ft_atoi(*(argv + 4))));
		ft_putchar('\n');
	}
	return (0);
}
