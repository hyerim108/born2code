# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 14:45:35 by hyerimki          #+#    #+#              #
#    Updated: 2022/07/06 16:59:04 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_isalnum.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_isdigit.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_calloc.c
OBJS = $(SRC:.c=.o)
NAME = libft.a

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