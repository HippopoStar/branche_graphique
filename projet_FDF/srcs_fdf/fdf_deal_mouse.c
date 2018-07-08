/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_deal_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:56:02 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/08 03:34:20 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_deal_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	ft_putnbr_base(button, "0123456789ABCDEF");
	fdf_pick_a_color(button, mouse_x, mouse_y, (t_fdf *)param)
	|| fdf_zoom(button, (t_fdf *)param)
	|| fdf_deplace(button, mouse_x, mouse_y, (t_fdf *)param);
	return (0);
}
