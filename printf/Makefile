# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 14:07:01 by hyerimki          #+#    #+#              #
#    Updated: 2022/07/15 16:35:24 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_plusnbr.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_putsymbol.c \
	ft_base.c \
	ft_memory.c
OBJS = $(SRC:.c=.o)
NAME = libftprintf.a
	
all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re