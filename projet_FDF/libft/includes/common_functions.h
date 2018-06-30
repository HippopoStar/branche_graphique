#ifndef COMMON_FUNCTIONS_H
# define COMMON_FUNCTIONS_H

void			ft_putnbr_base(int nbr, char *base);
char			**ft_split_whitespaces(char *str);
int				ft_two_power(int n);
int				ft_melt_colors(int red, int green, int blue);
void			ft_break_color_down(int *red, int *green, int *blue, int color);

#endif
