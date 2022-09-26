# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 15:01:32 by hyerimki          #+#    #+#              #
#    Updated: 2022/09/26 17:11:27 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c\
	push_swap.c\
	swap_push.c\
	pivot.c\
	rotate.c\
	reverse_rotate.c\
	ft_split.c\
	ft_atoi.c\
	setting_num.c\
	nogada.c\
	util.c\
	util2.c\
	util_size.c
	
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