# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:50:53 by hyerimki          #+#    #+#              #
#    Updated: 2023/01/16 12:43:17 by hyerimki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC = sources/main.c sources/setting.c sources/init.c sources/parsing.c \
	sources/color.c sources/map.c sources/check.c\
	sources/key_action.c sources/key_press.c sources/loop.c \
	sources/paint.c sources/go.c sources/raycasting.c\
	sources/init_ray.c sources/dda.c\
	gnl/get_next_line_utils.c \
	gnl/get_next_line.c \
	lib/utils.c lib/utils2.c

# OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJS = $(SRC:.c=.o)
NAME = cub3D
OBJ_DIR = ./obj

sp    = /-\|/
idx		=	0

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit
	@echo "\n$(COLOR)$(NAME) created!✅"
	
%.o : %.c
#@mkdir ./obj 2> /dev/null || true
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo "ʕ ̳• · • ̳ʔ \n  づ♡ =͟͟͞͞♡\n";\
				fi
	@printf "\b$(chr)"
	@$(CC) $(CFAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJS)
#@rm -rf	$(OBS_DIR)
	
fclean : clean
	@rm -rf ${NAME}
	@echo "$(COLOR)$(NAME) fclean!✅"

re : fclean all

.PHONY: all clean fclean re
