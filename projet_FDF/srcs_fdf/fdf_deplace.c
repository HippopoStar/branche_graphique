#include "fdf.h"

void	fdf_aux_deplace(int m_x, int m_y, t_fdf *win0)
{
	win0->ori_abs = win0->ori_abs + (m_x - win0->depla_x);
	win0->ori_ord = win0->ori_ord + (m_y - win0->depla_y);
	win0->depla_x = 0;
	win0->depla_y = 0;
	fdf_redraw_full(win0);
}

void	fdf_deplace(int button, int m_x, int m_y, t_fdf *win0)
{
	if (button == MLX_Pointer_Button3)
	{
		if (win0->depla_x == 0 && win0->depla_y == 0)
		{
			win0->depla_x = m_x;
			win0->depla_y = m_y;
			fdf_cross(m_x, m_y, 0xFF0000, win0);
		}
		else
		{
			fdf_aux_deplace(m_x, m_y, win0);
		}
	}
	else if (win0->depla_x != 0 || win0->depla_y != 0)
	{
		fdf_cross(win0->depla_x, win0->depla_y, 0x000000, win0);
		win0->depla_x = 0;
		win0->depla_y = 0;
	}
}