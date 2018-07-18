/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 02:38:53 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/18 04:48:10 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common_functions.h"

char	*ft_ptoa_base(void *ptr, const char *base, size_t pres, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;
	unsigned long long int	nb;

	l_n.content_size = 0;
	nb = (unsigned long long int)ptr;
	l_n.content = (void *)(&nb);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (pres == 0)
	{
		pres = 1;
	}
	l_length.content = (void *)(&pres);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}

char	*ft_uitoa_base(unsigned int n, const char *base,\
													size_t pres, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;
	unsigned long long int	nb;

	l_n.content_size = 0;
	nb = (unsigned long long int)n;
	l_n.content = (void *)(&nb);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (pres == 0)
	{
		pres = 1;
	}
	l_length.content = (void *)(&pres);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}

char	*ft_usitoa_base(unsigned short int n, const char *base,\
													size_t pres, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;
	unsigned long long int	nb;

	l_n.content_size = 0;
	nb = (unsigned long long int)n;
	l_n.content = (void *)(&nb);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (pres == 0)
	{
		pres = 1;
	}
	l_length.content = (void *)(&pres);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}

char	*ft_ulitoa_base(unsigned long int n, const char *base,\
													size_t pres, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;
	unsigned long long int	nb;

	l_n.content_size = 0;
	nb = (unsigned long long int)n;
	l_n.content = (void *)(&nb);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (pres == 0)
	{
		pres = 1;
	}
	l_length.content = (void *)(&pres);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}

char	*ft_ullitoa_base(unsigned long long int n, const char *base,\
													size_t pres, size_t spac)
{
	t_list					l_n;
	t_list					l_base;
	t_list					l_length;

	l_n.content_size = 0;
	l_n.content = (void *)(&n);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	if (!base || (l_base.content_size = ft_strlen(base)) < 2)
	{
		return (NULL);
	}
	l_base.next = &l_length;
	if (pres == 0)
	{
		pres = 1;
	}
	l_length.content = (void *)(&pres);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}
