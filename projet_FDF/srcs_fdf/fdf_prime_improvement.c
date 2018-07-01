#include "fdf.h"

void	fdf_assign_a_prime_number(t_point *p)
{
	int	a;
	int	b;

	if (p->x < 0)
		a = 5;
	else if (p->x < 720)
		a = 1;
	else
		a = 13;
	if (p->y < 0)
		b = 7;
	else if (p->y < 480)
		b = 1;
	else
		b = 11;
	p->prime = a * b;
}

int	fdf_prime_improvement(t_point *a, t_point *b)
{
	int	coef;

	coef = a->prime + b->prime;
	if (a->prime == 1 || b->prime == 1 || coef == 18)
	{
		return (1);
	}
	else if (coef % 7 == 0 || coef % 11 == 0 || coef % 13 == 0
			|| (coef % 5 == 0 && a->prime != 7 && a->prime != 13))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
