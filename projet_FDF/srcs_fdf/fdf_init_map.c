/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:57:40 by lcabanes          #+#    #+#             */
/*   Updated: 2018/07/12 06:42:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	fdf_count_fields(char *line, size_t width)
{
	size_t	i;
	size_t	witness;

	i = 0;
	while (*(line + i) == '\t' || *(line + i) == '\n' || *(line + i) == '\v'
			|| *(line + i) == '\f' || *(line + i) == '\r' || *(line + i) == ' ')
	{
		i++;
	}
	witness = 0;
	while (!(*(line + i) == '\t' || *(line + i) == '\n' || *(line + i) == '\v'
			|| *(line + i) == '\f' || *(line + i) == '\r' || *(line + i) == ' '
			|| *(line + i) == '\0'))
	{
		witness = 1;
		i++;
	}
	return ((*(line + i) == '\0') ? width + witness
									: fdf_count_fields(line + i, width + 1));
}

void	fdf_convert_lines_into_map(t_fdf *win0, char **spl, size_t i)
{
	size_t	j;

	j = 0;
	while (*(spl + j) != NULL)
	{
		j++;
	}
	if (j != win0->map_width)
	{
		fdf_error_code("fdf_convert_lines_into_map");
	}
	if (!(*(win0->map + i) = (int *)malloc(j * sizeof(int))))
	{
		fdf_error_code("fdf_convert_lines_into_map");
	}
	j = 0;
	while (j < win0->map_width)
	{
		*(*(win0->map + i) + j) = ft_atoi(*(spl + j));
		if (win0->max_val < *(*(win0->map + i) + j))
		{
			win0->max_val = *(*(win0->map + i) + j);
		}
		j++;
	}
}

void	fdf_split_file_lines(t_fdf *win0, t_fdf_line *last, size_t n)
{
	char		**spl;
	size_t		i;
	size_t		j;
	t_fdf_line	*line;

	if (!(win0->map = (int **)malloc(n * sizeof(int *))))
		fdf_error_code("fdf_split_file_lines");
	i = 1;
	line = last;
	while (i <= n)
	{
		spl = ft_split_whitespaces(line->str);
		free(line->str);
		line = line->next;
		fdf_convert_lines_into_map(win0, spl, n - i);
		j = 0;
		while (*(spl + j) != NULL)
		{
			free(*(spl + j));
			j++;
		}
		free(spl);
		i++;
	}
}

void	fdf_rec_get_file_lines(int fd, t_fdf *win0,\
												t_fdf_line *previous, size_t n)
{
	t_fdf_line	line;
	int			ret_gnl;
	size_t		ret_cf;

	line.next = previous;
	ret_gnl = get_next_line_backslash_zero(fd, &(line.str));
	if (ret_gnl == -1)
		fdf_error_code("fdf_rec_get_file_lines");
	else if (ret_gnl == 0)
	{
		free(line.str);
		if (!(line.next)
				|| !(win0->map_width = fdf_count_fields((line.next)->str, 0)))
			fdf_error_code("fdf_rec_get_file_lines");
		win0->map_height = n;
		fdf_split_file_lines(win0, line.next, n);
	}
	else
	{
		ft_putendl(line.str);
		(!(ret_cf = fdf_count_fields(line.str, 0)) || (ret_cf != win0->map_width
			&& win0->map_width != 0)) ? fdf_error_code("fdf_rec_get_file_lines")
			: (win0->map_width = ret_cf);
		fdf_rec_get_file_lines(fd, win0, &line, n + 1);
	}
}

void	fdf_init_map(char *file_name, t_fdf *win0)
{
	int	fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		fdf_error_code("fdf_init_map");
	}
	else
	{
		win0->map_width = 0;
		fdf_rec_get_file_lines(fd, win0, NULL, 0);
		if (close(fd) == -1)
		{
			fdf_error_code("fdf_init_map");
		}
	}
}
