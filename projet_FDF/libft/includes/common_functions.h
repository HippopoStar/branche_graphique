/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:09:19 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/17 03:26:19 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_FUNCTIONS_H
# define COMMON_FUNCTIONS_H

#include <wchar.h>

void			ft_putnbr_base(int nbr, char *base);
char			**ft_split_whitespaces(char *str);
int				ft_sqrt(int n);
int				ft_hypotenuse(int base, int hauteur);
int				ft_melt_colors(int red, int green, int blue);
void			ft_break_color_down(int *red, int *green, int *blue, int color);
char			*ft_itoa_base\
							(int n, const char *base, size_t pres, size_t spac);
char			*ft_widestring_to_string(wchar_t *widestring);

#endif
