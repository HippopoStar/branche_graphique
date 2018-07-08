# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/07/08 03:23:38 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes -I/usr/local/include/
LIBS	+=		-L./libft/ -lft -L/usr/local/lib/ -lmlx
LINUX	=		-lXext -lX11
MAC_OS	=		-framework OpenGL -framework AppKit

NAME = fdf

SRCS = ./srcs_fdf/main.c\
	./srcs_fdf/fdf_usage.c\
	./srcs_fdf/fdf_error_code.c\
	./srcs_fdf/fdf_bresenham.c\
	./srcs_fdf/fdf_bresenham_octants.c\
	./srcs_fdf/fdf_gradation.c\
	./srcs_fdf/fdf_prime_improvement.c\
	./srcs_fdf/fdf_init_struct.c\
	./srcs_fdf/fdf_color_palette.c\
	./srcs_fdf/fdf_init_map.c\
	./srcs_fdf/fdf_show_map.c\
	./srcs_fdf/fdf_allocate_to_pos.c\
	./srcs_fdf/fdf_projection.c\
	./srcs_fdf/fdf_color_pos.c\
	./srcs_fdf/fdf_draw.c\
	./srcs_fdf/fdf_deal_key.c\
	./srcs_fdf/fdf_deal_mouse.c\
	./srcs_fdf/fdf_zoom.c\
	./srcs_fdf/fdf_intensity.c\
	./srcs_fdf/fdf_deplace.c\
	./srcs_fdf/fdf_reset.c\
	./srcs_fdf/fdf_cross.c

OBJS = main.o\
	fdf_usage.o\
	fdf_error_code.o\
	fdf_bresenham.o\
	fdf_bresenham_octants.o\
	fdf_gradation.o\
	fdf_prime_improvement.o\
	fdf_init_struct.o\
	fdf_color_palette.o\
	fdf_init_map.o\
	fdf_show_map.o\
	fdf_allocate_to_pos.o\
	fdf_projection.o\
	fdf_color_pos.o\
	fdf_draw.o\
	fdf_deal_key.o\
	fdf_deal_mouse.o\
	fdf_zoom.o\
	fdf_intensity.o\
	fdf_deplace.o\
	fdf_reset.o\
	fdf_cross.o

all: $(NAME)

$(NAME):
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) $(OBJS) $(LIBS) $(MAC_OS)

clean:
	@make -C ./libft/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
