#include "fdf.h"

int	fdf_gradation(t_point cur, t_point des, int cur_dist, int tot_dist)
{
	int	color;
	int	red_diff;
	int	green_diff;
	int	blue_diff;

	red_diff = des.r - cur.r;
	green_diff = des.g - cur.g;
	blue_diff = des.b - cur.b;
	color = 0;
	color = color + (cur.r + ((red_diff * (tot_dist - cur_dist)) / tot_dist)) * 0x010000;
	color = color + (cur.g + ((green_diff * (tot_dist - cur_dist)) / tot_dist)) * 0x000100;
	color = color + (cur.b + ((blue_diff * (tot_dist - cur_dist)) / tot_dist));
	return (color);
}

/*
** Lors de l'appel de 'fdf_aux_bresenham', on a dors et deja
** l'assurance d'avoir [a, b] non vertical et {a} a gauche de {b}
*/

void	fdf_aux_bresenham(t_point a, t_point b, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;
	int		e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dy > 0)
	{
		if (dx >= dy)
		{
			e = dx;
			dx = dx * 2;
			dy = dy * 2;
			while (a.x < b.x)
			{
//				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xFFFFFF);
				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, fdf_gradation(a, b, b.x - a.x, dx / 2));
				a.x = a.x + 1;
				e = e - dy;
				if (e < 0)
				{
					a.y = a.y + 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = dy;
			dy = dy * 2;
			dx = dx * 2;
			while (a.y < b.y)
			{
//				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xFFFFFF);
				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, fdf_gradation(a, b, b.y - a.y, dy / 2));
				a.y = a.y + 1;
				e = e - dx;
				if (e < 0)
				{
					a.x = a.x + 1;
					e = e + dy;
				}
			}
		}
	}
	else if (dy < 0)
	{
		if (dx >= -dy)
		{
			e = dx;
			dx = dx * 2;
			dy = dy * 2;
			while (a.x < b.x)
			{
//				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xFFFFFF);
				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, fdf_gradation(a, b, b.x - a.x, dx / 2));
				a.x = a.x + 1;
				e = e + dy;
				if (e < 0)
				{
					a.y = a.y - 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = dy;
			dy = dy * 2;
			dx = dx * 2;
			while (a.y > b.y)
			{
//				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xFFFFFF);
				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, fdf_gradation(a, b, b.y - a.y, dy / 2));
				a.y = a.y - 1;
				e = e + dx;
				if (e > 0)
				{
					a.x = a.x + 1;
					e = e + dy;
				}
			}
		}
	}
	else
	{
		while (a.x < b.x)
		{
//			mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, fdf_gradation(a, b, b.x - a.x, dx));
			a.x = a.x + 1;
		}
	}
}

/*
** La fonction 'fdf_bresenham', selon les caracteristiques du segment [a, b] :
** - ne fait rien si {a} et {b} confondus
** - trace [a, b] si a->b vertical oriente vers le bas
** - se rappelle elle-meme en intervertissant {a} et {b} si a->b vertical oriente vers le haut
** - appelle 'fdf_aux_bresenham' si a->b non vertical avec a->b oriente vers la droite
** - appelle 'fdf_aux_bresenham' en intervertissant {a} et {b} si a->b non vertical oriente vers la gauche
*/

void	fdf_bresenham(t_point a, t_point b, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx != 0)
	{
		(dx > 0) ? fdf_aux_bresenham(a, b, mlx_ptr, win_ptr)
			: fdf_aux_bresenham(b, a, mlx_ptr, win_ptr);
	}
	else
	{
		if (dy > 0)
		{
			while (a.y < b.y)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0xFFFFFF);
				a.y = a.y + 1;
			}
		}
		else if (dy < 0)
		{
			fdf_bresenham(b, a, mlx_ptr, win_ptr);
		}
	}
}
