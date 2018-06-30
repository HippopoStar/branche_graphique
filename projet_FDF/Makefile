# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/04/19 22:39:22 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I/usr/local/include/ -I./libft/includes -I./
CFLAGS	+=		-L/usr/local/lib/ -L./libft/
LIBS		=	-lft -lmlx -lXext -lX11
FRAMEWORKS	=	-framework OpenGL -framework AppKit

NAME = fdf

SRCS = ./srcs_fdf/main.c\
       ./srcs_fdf/fdf_usage.c\
       ./srcs_fdf/fdf_error_code.c\
       ./srcs_fdf/fdf_bresenham.c\
       ./srcs_fdf/fdf_init_struct.c\
       ./srcs_fdf/fdf_init_map.c\
       ./srcs_fdf/fdf_show_map.c\
       ./srcs_fdf/fdf_init_pos_map.c\
       ./srcs_fdf/fdf_projection.c\
       ./srcs_fdf/fdf_draw.c

OBJS = main.o\
       fdf_usage.o\
       fdf_error_code.o\
       fdf_bresenham.o\
       fdf_init_struct.o\
       fdf_init_map.o\
       fdf_show_map.o\
       fdf_init_pos_map.o\
       fdf_projection.o\
       fdf_draw.o

all: $(NAME)

$(NAME):
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) $(OBJS) $(LIBS)

clean:
#	@make -C ./libft/ clean
	rm -f $(OBJS)

fclean: clean
#	@make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
