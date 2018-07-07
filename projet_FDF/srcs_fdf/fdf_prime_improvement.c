/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prime_improvement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:59:22 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 20:27:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** On assigne aux differentes positions de points un nombre
** suivant le schema suivant :
**	35	|	7	|	91
** -------------+---------------+---------------
**	5	|	SCREEN	|	13
** -------------+---------------+---------------
**	55	|	11	|	141
**
** Par ailleurs, on a :
** 5 + 7	= 12
**		= 2^(2) * 3
** 5 + 11	= 16
**		= 2^(4)
** / ! \ 7 + 13	= 20
**		= 2^(2) * 5
** 11 + 13	= 24
**		= 2^(3) * 3
** 5 + 91	= 96
**		= 2^(5) *3
** 5 + 141	= 146
**		= 2 * 73
** 7 + 55	= 62
**		= 2 * 31
** 7 + 141	= 148
**		= 2^(2) * 37
** 11 + 35	= 46
**		= 2 * 23
** 11 + 91	= 102
**		= 2 * 3 * 17
** 13 + 35	= 48
**		= 2^(4) * 3
** 13 + 55	= 68
**		= 2^(2) * 17
*/

void	fdf_assign_a_prime_number(t_point *p)
{
	int	a;
	int	b;

	if (p->x < 0)
		a = 5;
	else if (p->x < WIN0_SX)
		a = 1;
	else
		a = 13;
	if (p->y < 0)
		b = 7;
	else if (p->y < WIN0_SY)
		b = 1;
	else
		b = 11;
	p->prime = a * b;
}

int		fdf_prime_improvement(t_point *a, t_point *b)
{
	int	coef;

	coef = a->prime + b->prime;
	if (a->prime == 1 || b->prime == 1 || coef == 18)
	{
		return (1);
	}
	else if (coef % 7 == 0 || coef % 11 == 0 || coef % 13 == 0
			|| (coef % 5 == 0 && !(a->prime == 7 || a->prime == 13)))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
