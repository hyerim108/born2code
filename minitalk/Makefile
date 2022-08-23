# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 14:07:01 by hyerimki          #+#    #+#              #
#    Updated: 2022/08/23 15:21:16 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c \
			ft_put_fd.c

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)
	
all : ${SERVER} ${CLIENT}

%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@

${CLIENT}:		${OBJS_CLIENT}
				${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT}

${SERVER}:		${OBJS_SERVER}
				${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER}
				
clean :
	rm -rf $(OBJS_CLIENT) ${OBJS_SERVER}

fclean : clean
	rm -rf server client

re : fclean all

.PHONY: all clean fclean re