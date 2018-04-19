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
CFLAGS	+=		-I /usr/local/include/
FRAMEWORKS	=	-framework OpenGL -framework AppKit

NAME = basic.out

SRCS = main_basic.c

OBJS = main_basic.o

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L /usr/local/lib/ $(OBJS) -lmlx $(FRAMEWORKS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
