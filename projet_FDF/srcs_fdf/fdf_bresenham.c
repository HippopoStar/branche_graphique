#include "fdf.h"

/*
** Lors de l'appel de 'fdf_aux1_bresenham', on a dors et deja
** l'assurance d'avoir [a, b] non vertical et {a} a gauche de {b}
*/

void	fdf_aux1_bresenham(t_point a, t_point b, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dy > 0)
	{
		if (dx >= dy)
		{
			fdf_bresenham_1st_octant(a, b, mlx_ptr, win_ptr);
		}
		else
		{
			fdf_bresenham_2nd_octant(a, b, mlx_ptr, win_ptr);
		}
	}
	else if (dy < 0)
	{
		if (dx >= -dy)
		{
			fdf_bresenham_8th_octant(a, b, mlx_ptr, win_ptr);
		}
		else
		{
			fdf_bresenham_7th_octant(a, b, mlx_ptr, win_ptr);
		}
	}
	else
	{
		while (a.x < b.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, fdf_gradation(a, b, b.x - a.x, dx));
			a.x = a.x + 1;
		}
	}
}

/*
** La fonction 'fdf_aux0_bresenham', selon les caracteristiques du segment [a, b] :
** - ne fait rien si {a} et {b} confondus
** - trace [a, b] si a->b vertical oriente vers le bas
** - se rappelle elle-meme en intervertissant {a} et {b} si a->b vertical oriente vers le haut
** - appelle 'fdf_aux1_bresenham' si a->b non vertical avec a->b oriente vers la droite
** - appelle 'fdf_aux1_bresenham' en intervertissant {a} et {b} si a->b non vertical oriente vers la gauche
*/

void	fdf_aux0_bresenham(t_point a, t_point b, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx != 0)
	{
		(dx > 0) ? fdf_aux1_bresenham(a, b, mlx_ptr, win_ptr)
			: fdf_aux1_bresenham(b, a, mlx_ptr, win_ptr);
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
			fdf_aux0_bresenham(b, a, mlx_ptr, win_ptr);
		}
	}
}

void	fdf_bresenham(t_point *a, t_point *b, void *mlx_ptr, void *win_ptr)
{
	if (fdf_prime_improvement(a, b))
	{
		fdf_aux0_bresenham(*a, *b, mlx_ptr, win_ptr);
	}
}
