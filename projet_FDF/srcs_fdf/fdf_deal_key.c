/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_deal_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:55:51 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/09 03:27:20 by lcabanes         ###   ########.fr       */
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
		if (fdf_spacing(key, (t_fdf *)param)
		|| fdf_intensity(key, (t_fdf *)param)
		|| fdf_reset(key, (t_fdf *)param)
		|| fdf_optimize(key, (t_fdf *)param))
			return (0);
	}
	return (0);
}
