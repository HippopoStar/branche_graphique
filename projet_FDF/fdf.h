/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:17:07 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 03:22:36 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "common_functions.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define WIN0_TITLE				"FDF"
# define WIN0_SX				720
# define WIN0_SY				480
# define CP_X0					5
# define CP_Y0					5
# define CROSS_SIZE				3
# define FDF_DEFAULT_ZOOM		1
# define FDF_DEFAULT_SPACING	10
# define FDF_DEFAULT_INTENSITY	1
# define ORI_ABS				200
# define ORI_ORD				30

/*
** ASSIGNATIONS MAC_OS
*/
/*
** # define MLX_ESCAPE				0x0035
** # define MLX_UP					0x007E
** # define MLX_DOWN				0x007D
** # define MLX_D					0x0002
** # define MLX_I					0x0022
** # define MLX_R					0x000F
** # define MLX_U					0x0020
** # define MLX_POINTER_BUTTON1	0x0001
** # define MLX_POINTER_BUTTON3	0x0002
** # define MLX_POINTER_BUTTON4	0x0004
** # define MLX_POINTER_BUTTON5	0x0005
*/

/*
** ASSIGNATIONS LINUX
*/
# define MLX_ESCAPE				0xFF1B
# define MLX_UP					0xFF52
# define MLX_DOWN				0xFF54
# define MLX_D					0x0064
# define MLX_I					0x0069
# define MLX_R					0x0072
# define MLX_U					0x0075
# define MLX_POINTER_BUTTON1		0x0001
# define MLX_POINTER_BUTTON3		0x0003
# define MLX_POINTER_BUTTON4		0x0004
# define MLX_POINTER_BUTTON5		0x0005

typedef struct			s_point
{
	int					x;
	int					y;
	int					prime;
	int					r;
	int					g;
	int					b;
}						t_point;

typedef struct			s_mlx_img
{
	void				*img_ptr;
	char				*img_str;
	int					bpp;
	int					s_l;
	int					endian;
	int					width;
	int					height;
}						t_mlx_img;

typedef struct			s_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_mlx_img			*mlx_img_fdf;
	t_mlx_img			*mlx_img_cp;
	int					ori_abs;
	int					ori_ord;
	int					**map;
	size_t				map_width;
	size_t				map_height;
	int					max_val;
	int					optimize;
	int					zoom;
	int					spacing;
	int					intensity;
	int					depla_x;
	int					depla_y;
	t_point				**pos;
	int					color;
	int					r0;
	int					g0;
	int					b0;
}						t_fdf;

typedef struct			s_fdf_line
{
	char				*str;
	struct s_fdf_line	*next;
}						t_fdf_line;

void					fdf_usage(void);
void					fdf_error_code(char *error_message);
void					fdf_imp_bresenham\
						(t_point *a, t_point *b, void *mlx_ptr, void *win_ptr);
void					fdf_bresenham_1st_octant\
						(t_point a, t_point b, void *mlx_ptr, void *win_ptr);
void					fdf_bresenham_2nd_octant\
						(t_point a, t_point b, void *mlx_ptr, void *win_ptr);
void					fdf_bresenham_8th_octant\
						(t_point a, t_point b, void *mlx_ptr, void *win_ptr);
void					fdf_bresenham_7th_octant\
						(t_point a, t_point b, void *mlx_ptr, void *win_ptr);
void					fdf_img_imp_bresenham\
									(t_point *a, t_point *b, t_mlx_img *pic);
void					fdf_img_bresenham_1st_octant\
										(t_point a, t_point b, t_mlx_img *pic);
void					fdf_img_bresenham_2nd_octant\
										(t_point a, t_point b, t_mlx_img *pic);
void					fdf_img_bresenham_8th_octant\
										(t_point a, t_point b, t_mlx_img *pic);
void					fdf_img_bresenham_7th_octant\
										(t_point a, t_point b, t_mlx_img *pic);
int						fdf_gradation\
						(t_point cur, t_point des, int cur_dist, int tot_dist);
int						fdf_prime_improvement(t_point *a, t_point *b);
void					fdf_assign_a_prime_number(t_point *p);
void					fdf_init_struct\
							(int width, int height, char *title, t_fdf **win0);
void					fdf_init_images(t_fdf *win0);
void					fdf_init_img_fdf(t_fdf *win0);
void					fdf_clear_img(t_mlx_img *pic);
void					fdf_put_px_into_img\
									(t_mlx_img *pic, int x, int y, int color);
void					fdf_color_palette\
								(void *mlx_ptr, void *win_ptr, int x0, int y0);
void					fdf_img_color_palette(t_mlx_img *pic);
void					fdf_apply_zoom(int *n, t_fdf *win0);
void					fdf_init_map(char *file_name, t_fdf *win0);
void					fdf_show_map(t_fdf *win0);
void					fdf_allocate_to_pos(t_fdf *win0);
void					fdf_projection\
				(t_fdf *win0, void (*f)(t_point *, size_t, size_t, t_fdf *));
void					fdf_iso(t_point *pos, size_t i, size_t j, t_fdf *win0);
void					fdf_color_pos(t_fdf *win0);
int						fdf_pick_a_color\
								(int m_button, int m_x, int m_y, t_fdf *win0);
void					fdf_draw(t_fdf *win0, t_point **pos);
void					fdf_redraw(t_fdf *win0);
void					fdf_redraw_full(t_fdf *win0);
void					fdf_img_draw(t_fdf *win0, t_point **pos);
void					fdf_img_redraw(t_fdf *win0);
void					fdf_img_redraw_full(t_fdf *win0);
void					fdf_display_parameters(t_fdf *win0);
int						fdf_deal_key(int key, void *param);
int						fdf_deal_mouse\
							(int button, int mouse_x, int mouse_y, void *param);
int						fdf_optimize(int key, t_fdf *win0);
int						fdf_zoom(int button, t_fdf *win0);
int						fdf_spacing(int key, t_fdf *win0);
int						fdf_intensity(int key, t_fdf *win0);
int						fdf_deplace(int button, int m_x, int m_y, t_fdf *win0);
int						fdf_reset(int key, t_fdf *win0);
void					fdf_cross(int x0, int y0, int color, t_fdf *win0);

#endif
