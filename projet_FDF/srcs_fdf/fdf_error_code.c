#include "fdf.h"

void	fdf_error_code(char *error_message)
{
	ft_putstr(error_message);
	ft_putchar('\n');
	exit (0);
}
