ifneq ($(shell uname), Linux)
READLINE_LIB_DIR_FLAG := -L$(shell brew --prefix readline)/lib
READLINE_INC_DIR_FLAG := -I$(shell brew --prefix readline)/include
endif

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
YELLOW		= \033[0;33m
RST			= \033[0m
END			= \e[0m

SRCS		= minishell.c \
			  sources/built/ft_built_in.c \
			  sources/built/ft_built_in_2.c \
			  sources/built/ft_built.c \
			  sources/cmd/ft_get_infile.c \
			  sources/cmd/ft_get_infile_2.c \
			  sources/cmd/ft_get_outfile.c \
			  sources/cmd/ft_get_outfile_2.c \
			  sources/cmd/ft_check_dir.c \
			  sources/cmd/ft_getfd.c \
			  sources/cmd/ft_heredoc.c \
			  sources/cmd/ft_heredoc_2.c \
			  sources/cmd/ft_cd.c \
			  sources/cmd/ft_cd_error.c \
			  sources/cmd/ft_check_cmd.c \
			  sources/cmd/ft_echo.c \
			  sources/cmd/ft_exit.c \
			  sources/cmd/ft_find_cmd.c \
			  sources/cmd/ft_pwd.c \
			  sources/cmd/ft_export.c \
			  sources/cmd/ft_export_2.c \
			  sources/cmd/ft_exp_error.c \
			  sources/cmd/ft_ch_env_name.c \
			  sources/cmd/ft_unset.c \
			  sources/cmd/ft_cmd_env.c \
			  sources/cmd/ft_cmd_export.c \
			  sources/parsing/ft_cmd_split.c \
			  sources/parsing/ft_expand_cmd.c \
			  sources/parsing/ft_expand_path.c \
			  sources/parsing/ft_fill_cmd.c \
			  sources/parsing/ft_fill_cmd_2.c \
			  sources/parsing/ft_free_cmd.c \
			  sources/parsing/ft_free_fd.c \
			  sources/parsing/ft_get_strchar_val.c \
			  sources/parsing/ft_lock_cmd.c \
			  sources/parsing/ft_lock_trim_cmd.c \
			  sources/parsing/ft_replace.c \
			  sources/parsing/ft_resolve_cmd.c \
			  sources/parsing/ft_strchar_i.c \
			  sources/parsing/ft_split_cmd.c \
			  sources/parsing/ft_word_count.c \
			  sources/parsing/ft_cmd_count.c \
			  sources/utils/ft_atol.c \
			  sources/utils/ft_check_ag.c \
			  sources/utils/ft_count_len.c \
			  sources/utils/ft_count_char.c \
			  sources/utils/ft_create_cmd.c \
			  sources/utils/ft_search_user.c \
			  sources/utils/ft_env_split.c \
			  sources/utils/ft_extend_split.c \
			  sources/utils/ft_free_split.c \
			  sources/utils/ft_get_dir.c \
			  sources/utils/ft_get_envalue.c \
			  sources/utils/ft_redirec_pipe.c \
			  sources/utils/ft_get_prompt.c \
			  sources/utils/ft_get_user.c \
			  sources/utils/ft_getpid.c \
			  sources/utils/ft_init.c \
			  sources/utils/ft_init_data.c \
			  sources/utils/ft_isspace.c \
			  sources/utils/ft_n_rows.c \
			  sources/utils/ft_perror.c \
			  sources/utils/ft_search_env.c \
			  sources/utils/ft_split_all.c \
			  sources/utils/ft_strchr_r.c \
			  sources/utils/ft_strtrim_mini.c \
			  sources/utils/ft_update_user.c \
			  sources/utils/get_next_line.c \
			  sources/utils/get_next_line_utils.c \
			  sources/utils/ft_env_var.c \
			  sources/utils/ft_find_str.c \
			  sources/pipex/ft_check_fork.c \
			  sources/pipex/ft_fork.c \
			  sources/pipex/ft_fork_2.c \
			  sources/pipex/ft_fork_3.c \
			  sources/pipex/ft_fork_4.c \
			  sources/pipex/ft_get_cmd.c \
			  sources/pipex/ft_run_cmd.c \
			  sources/signal/ft_sig_c.c \
			  sources/signal/ft_sig_q.c \
			  				  
NAME		= minishell
OBJS_DIR	= objs/
PROJECT_H	= includes/minishell.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -g3 -fsanitize=address -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c $(PROJECT_H) Makefile
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)sources
	@mkdir -p $(OBJS_DIR)sources/parsing
	@mkdir -p $(OBJS_DIR)sources/utils
	@mkdir -p $(OBJS_DIR)sources/signal
	@mkdir -p $(OBJS_DIR)sources/built
	@mkdir -p $(OBJS_DIR)sources/pipex
	@mkdir -p $(OBJS_DIR)sources/cmd
	@$(CC) $(READLINE_INC_DIR_FLAG) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${YELLOW}[Build - minishell]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker Makefile
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(READLINE_LIB_DIR_FLAG) libft/libft.a -lreadline
	@printf "\033[2K\r\033[0;32m[Compile END!!!]\033[0m $(NAME)$(END)\n"

all: $(NAME)

maker:
	@make -C libft

clean:
	@make clean -C libft
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

.PHONY:		all clean fclean re
