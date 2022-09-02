# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:01:32 by hyerimki          #+#    #+#              #
#    Updated: 2022/09/02 15:51:32 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	utils.c \
	error.c \
	build_map.c \
	key_press.c \
	gnl/get_next_line_utils.c \
	gnl/get_next_line.c

OBJS = $(SRC:.c=.o)
NAME = so_long

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit
# $(NAME) : $(OBJS)
# 	ar rc $@ $^ -lmlx -framework OpenGL -framework AppKit
	
%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re