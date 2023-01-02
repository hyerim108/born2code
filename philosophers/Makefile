# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 17:10:27 by hyerimki          #+#    #+#              #
#    Updated: 2023/01/02 15:05:13 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
# -g -fsanitize=thread
SRC = main.c \
	threads.c\
	util.c \
	action.c \
	message.c 
OBJS = $(SRC:.c=.o)

COLOR = \033[33m
NAME = philo
	
all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(COLOR)$(NAME) created!✅"
	
%.o : %.c
	@$(CC) $(CFAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJS)
	@echo "$(NAME) clean"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(NAME) fclean"

re : 
	make fclean 
	make all

.PHONY: all clean fclean re
