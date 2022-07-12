# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 14:45:35 by hyerimki          #+#    #+#              #
#    Updated: 2022/07/12 13:27:30 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
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
		ft_calloc.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c
		
BOUNUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
OBJS = $(SRC:.c=.o)
OBJS_B = $(BOUNUS:.c=.o)
NAME = libft.a

ifdef BOUNUS2
	OBJ = $(OBJS) $(OBJS_B)
else
	OBJ = $(OBJS)
endif
	
all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@

bonus :
	make BOUNUS2=1 all

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re