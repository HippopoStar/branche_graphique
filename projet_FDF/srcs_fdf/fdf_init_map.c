#include "fdf.h"

void	fdf_convert_lines_into_map(t_fdf *win0, char **spl, size_t i)
{
	size_t	j;

	j = 0;
	while (*(spl + j) != NULL)
	{
		j++;
	}
	(win0->map_width == j || win0->map_width == 0) ?
		win0->map_width = j
		: fdf_error_code("fdf_convert_lines_into_map");
	if (!(*(win0->map + i) = (int *)malloc((j + 1) * sizeof(int))))
	{
		fdf_error_code("fdf_convert_lines_into_map");
	}
	j = 0;
	while (j < win0->map_width)
	{
		*(*(win0->map + i) + j) = ft_atoi(*(spl + j));
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
	{
		fdf_error_code("fdf_split_file_lines");
	}
	i = 0;
	line = last;
	while (i < n)
	{
		spl = ft_split_whitespaces(line->str);
		free(line->str);
		fdf_convert_lines_into_map(win0, spl, n - i);
		j = 0;
		while (*(spl + j) != NULL)
		{
			free(*(spl + j));
		}
		free(spl);
		i++;
	}
}

void	fdf_rec_get_file_lines(int fd, t_fdf *win0, t_fdf_line *previous, size_t n)
{
	t_fdf_line	line;
	int		ret_gnl;

	line.next = previous;
	ret_gnl = get_next_line(fd, &(line.str));
	if (ret_gnl == -1)
	{
		fdf_error_code("fdf_rec_get_file_lines");
	}
	else if (ret_gnl == 0)
	{
		win0->map_width = 0;
		win0->map_heigth = n;
		fdf_split_file_lines(win0, &line, n);
	}
	else
	{
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
		fdf_rec_get_file_lines(fd, win0, NULL, 0);
	}
}
