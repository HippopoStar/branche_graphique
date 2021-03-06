/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:57:12 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/07 20:18:53 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error_code(char *error_message)
{
	ft_putstr("error: ");
	ft_putstr(error_message);
	ft_putchar('\n');
	exit(0);
}
