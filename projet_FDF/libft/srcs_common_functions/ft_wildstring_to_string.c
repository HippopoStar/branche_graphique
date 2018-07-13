/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildstring_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:20:59 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/13 16:15:43 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** On a :
** [ 1100 0000 | 0000 0000 ] = 49 152
** [ 1110 0000 | 0000 0000 | 0000 0000 ] = 14 680 064
** [ 1111 0000 | 0000 0000 | 0000 0000 | 0000 0000 ] = 4 026 531 840
*/

unsigned int	ft_wildchar_to_unsigned_int(wint_t wildchar)
{
	unsigned int	n;
	unsigned int	i;

	n = 0;
	i = 1;
	while ((unsigned int)wildchar / i != 0)
	{
		if (i >> 4 == 1 || i >> 12 == 1 || i >> 20 == 1)
		{
			n = n + (i << 1);
			i = i << 2;
		}
		n = n + (((unsigned int)wildchar % 2) * i);
		i = i << 1;
	}
	if (n >> 24 > 0)
		n = n + 4026531840;
	else if (n >> 16 > 0)
		n = n + 14680064;
	else if (n >> 8 > 0)
		n = n + 49152;
	return (n);
}
