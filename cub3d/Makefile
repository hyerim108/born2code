# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:50:53 by hyerimki          #+#    #+#              #
#    Updated: 2023/01/06 18:13:29 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c setting.c utils.c \
	gnl/get_next_line_utils.c \
	gnl/get_next_line.c

OBJS = $(SRC:.c=.o)
NAME = cub3D

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit
	
%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re