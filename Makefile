# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 16:17:45 by mde-la-s          #+#    #+#              #
#    Updated: 2021/09/25 16:14:01 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

LIBFT	=	libft/libft.a
MLX		=	minilibx-linux/libmlx.a
SRCS	=	fractol.c \
			srcs/utils.c \
			srcs/utils2.c \
			srcs/create_img_julia.c \
			srcs/create_img_mandelbrot.c \
			srcs/create_img_sponge.c \
			srcs/create_img_burning_ship.c \
			srcs/colors.c \
			srcs/prints.c \
			srcs/events.c

# Colors
_GREY=$ \x1b[30m
_RED=$ \x1b[31m
_GREEN=$ \x1b[32m
_YELLOW=$ \x1b[33m
_BLUE=$ \x1b[34m
_PURPLE=$ \x1b[35m
_CYAN=$ \x1b[36m
_WHITE=$ \x1b[37m
_END=$ \x1b[0m

CC		=	clang
CFLAGS	=	-Werror -Wextra -Wall -I./headers -I./minilibx-linux
CFLAGS2 =	-L minilibx-linux -lmlx -lXext -lX11 -lm

OBJS	=	${SRCS:.c=.o}

all		:	${NAME}

$(NAME)	:	${OBJS}
		${MAKE} -C ./minilibx-linux
		@echo "$(_GREEN)MINILIBX OK${_END}"
		${MAKE} -C ./libft
		${MAKE} bonus -C ./libft
		@echo "$(_GREEN)LIBFT OK${_END}"
		${CC} ${CFLAGS} ${CFLAGS2} -o $(NAME) ${OBJS} ${LIBFT} ${MLX}
		@echo "$(_GREEN)FRACTOL OK${_END}"

clean	:
		${MAKE} clean -C libft
		${MAKE} clean -C minilibx-linux
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
