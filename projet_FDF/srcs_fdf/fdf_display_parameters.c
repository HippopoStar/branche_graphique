/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_parameters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 04:22:33 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/09 05:06:46 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_parameters(t_fdf *win0)
{
	int		x;
	int		y;
	char	*ret_itoa;

	x = CP_X0;
	y = CP_Y0 + 128 + 15;
	mlx_string_put(win0->mlx_ptr, win0->win_ptr, x, y, 0x7F7F7F, "zoom :");
	mlx_string_put(win0->mlx_ptr, win0->win_ptr, x + 120, y, 0x7F7F7F,\
			(ret_itoa = ft_itoa(win0->zoom)));
	free(ret_itoa);
	y = y + 20;
	mlx_string_put(win0->mlx_ptr, win0->win_ptr, x, y, 0x7F7F7F, "spacing :");
	mlx_string_put(win0->mlx_ptr, win0->win_ptr, x + 120, y, 0x7F7F7F,\
			(ret_itoa = ft_itoa(win0->spacing)));
	free(ret_itoa);
	y = y + 20;
	mlx_string_put(win0->mlx_ptr, win0->win_ptr, x, y, 0x7F7F7F, "intensity :");
	mlx_string_put(win0->mlx_ptr, win0->win_ptr, x + 120, y, 0x7F7F7F,\
			(ret_itoa = ft_itoa(win0->intensity)));
	free(ret_itoa);
}
