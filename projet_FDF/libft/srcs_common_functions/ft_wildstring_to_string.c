/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildstring_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:20:59 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/17 01:21:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** On a :
** [ 1100 0000 | 0000 0000 ] = 49 152
** [ 1110 0000 | 0000 0000 | 0000 0000 ] = 14 680 064
** [ 1111 0000 | 0000 0000 | 0000 0000 | 0000 0000 ] = 4 026 531 840
*/

static unsigned int	ft_wildchar_to_unsigned_int(wint_t wildchar)
{
	unsigned int	n;
	unsigned int	i;
	unsigned int	j;

	n = 0;
	i = 1;
	j = 1;
	while ((unsigned int)wildchar / i != 0)
	{
		if (j >> 6 == 1 || j >> 14 == 1 || j >> 22 == 1)
		{
			n = n + (j << 1);
			j = j << 2;
		}
		n = n + ((((unsigned int)wildchar / i) % 2) * j);
		i = i << 1;
		j = j << 1;
	}
	if (n >> 24 > 0)
		n = n + 4026531840;
	else if (n >> 16 > 0)
		n = n + 14680064;
	else if (n >> 8 > 0)
		n = n + 49152;
	return (n);
}

/*
** [0000 0001 | 0000 0000 | 0000 0000 | 0000 0000] = 2^(24)	= 16 777 216
** [0000 0000 | 0000 0001 | 0000 0000 | 0000 0000] = 2^(16)	= 65 536
** [0000 0000 | 0000 0000 | 0000 0001 | 0000 0000] = 2^(8)	= 256
** [0000 0000 | 0000 0000 | 0000 0000 | 0000 0001] = 2^(0)	= 1
*/

static void			ft_unsigned_int_to_string(unsigned int wildchar,\
																	char str[5])
{
	size_t	i;
	size_t	j;

	i = 4;
	j = 0;
	while (i != 0)
	{
		i--;
		if ((str[j] = (char)((wildchar >> (8 * i)) % 256)) != '\0')
		{
			j++;
		}
	}
	str[j] = '\0';
}

char			*ft_wildstring_to_string(wchar_t *wildstring)
{
	char			*str;
	char			wildchar[5];
	unsigned int	n;
	size_t			size;
	size_t			i;
	size_t			j;

	size = 0;
	while (*(wildstring + size) != L'\0')
	{
		size++;
	}
	if (!(str = (char *)malloc(((4 * size) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		n = ft_wildchar_to_unsigned_int((wint_t)*(wildstring + i));
		ft_unsigned_int_to_string(n, wildchar);
		ft_strcpy((str + j), wildchar);
		j = j + ft_strlen(wildchar);
		i++;
	}
	*(str + j) = '\0';
	return (str);
}
