# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 16:17:45 by mde-la-s          #+#    #+#              #
#    Updated: 2021/09/13 17:03:37 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
NAMEBON	=	bonus

LIBFT	=	libft/libft.a
MLX		=	minilibx/libmlx.a
SRCS	=	fractol.c \
			srcs/utils.c \
			srcs/launch_win.c

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
CFLAGS	=	-Werror -Wextra -Wall -I./headers -I./minilibx 
CFLAGS2 =	-framework OpenGL -framework AppKit

OBJS	=	${SRCS:.c=.o}

all		:	${NAME}

$(NAME)	:	${OBJS}
		${MAKE} -C ./minilibx
		@echo "$(_GREEN)MINILIBX OK${_END}"
		${MAKE} -C ./libft
		${MAKE} bonus -C ./libft
		@echo "$(_GREEN)LIBFT OK${_END}"
		${CC} ${CFLAGS} ${CFLAGS2} -o $(NAME) ${OBJS} ${LIBFT} ${MLX}
		@echo "$(_GREEN)FRACTOL OK${_END}"

$(NAMEBON)	:	${OBJSBON}
		${MAKE} -C ./libft
		${MAKE} bonus -C ./libft
		${CC} ${CFLAGS} -o $(NAMEBON) ${OBJSBON} ${LIBFT}
		@echo "$(_GREEN)BONUS OK${_END}"

clean	:
		${MAKE} clean -C libft
		rm -f ${OBJS} ${OBJSBON}

fclean	:	clean
		rm -f ${NAME} ${NAMEBON}

re		:	fclean all

.PHONY	:	all clean fclean re
