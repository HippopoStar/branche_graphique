/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 22:18:10 by lcabanes          #+#    #+#             */
/*   Updated: 2018/04/19 23:11:42 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, void *param)
{
	(void)key;
	(void)param;
	ft_putchar('X');
//	mlx_pixel_put(mlx_ptr, win_ptr, [...]);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
