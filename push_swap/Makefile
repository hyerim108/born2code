# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:01:32 by hyerimki          #+#    #+#              #
#    Updated: 2022/09/19 16:16:43 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	ft_split.c \
	push_swap.c \
	swap_push.c \
	util.c \
	util2.c \
	util_etc.c \
	rotate.c \
	reverse_rotate.c
	
OBJS = $(SRC:.c=.o)
NAME = push_swap

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o $@ $^
	
%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re