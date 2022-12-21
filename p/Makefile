SRCS 	= main.c	init.c	utils.c		actions.c	message.c	time.c utils2.c

OBJS 	= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra -g -fsanitize=thread

NAME	= philo

all:		$(OBJS)
			-@gcc -o $(NAME) $(OBJS)

clean:
			-@rm -f $(OBJS)

fclean: 	clean
			-@rm -f $(NAME)

re:	fclean all

.PHONY: all clea fclean re