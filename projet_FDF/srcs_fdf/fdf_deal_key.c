/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_deal_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:55:51 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 03:37:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_deal_key(int key, void *param)
{
	ft_putnbr_base(key, "0123456789ABCDEF");
	if (key == MLX_ESCAPE)
	{
		exit(0);
	}
	else
	{
		fdf_intensity(key, (t_fdf *)param)
		|| fdf_reset(key, (t_fdf *)param);
	}
	return (0);
}
