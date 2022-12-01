/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:44:46 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 17:52:09 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <signal.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include "readline/history.h"
# include "readline/readline.h"

# define READ_END 0
# define WRITE_END 1

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define CYAN "\001\033[1;96m\002"

typedef struct s_data
{
	t_list	*cmds;
	pid_t	pid;
	char	**env;
}	t_data;

typedef struct s_cmd
{
	char	**f_cmd;
	char	*f_path;
	int		input_fd;
	int		output_fd;
}	t_cmd;

enum	e_error
{
	NDIR = 1,
	QUOTE = 2,
	NPERM = 3,
	PIPERR = 4,
	FORKERR = 5,
	ISDIR = 6,
	NOT_DIR = 7,
	DUPERR = 8,
	NCMD = 9
};

int			g_status_number;

int			ft_built(t_cmd *cmd);
int			ft_built_in(t_data *data, t_list *cmd, int *exit_n, int n);
int			ft_built_in_2(t_data *data, t_list *cmd, char **str, int n);

char		**ft_cmd_split(char *in_cmd, char *set);
char		*ft_expand_cmd(char *in_cmd, int i, int q[2], t_data *data);
char		*ft_expand_path(char *in_cmd, int i, int q[2], char *var);
char		**ft_fill_cmd(char **str, const char *in_cmd, char *set, int q[3]);
char		**ft_fill_cmd_2(char **str, const char *in_cmd, char *c, int q[3]);
t_list		*ft_free_cmd(t_list *cmds, char **in_cmd, char **tmp);
void		ft_free_fd(void *content);
char		*ft_get_strchar_val(char *in_cmd, int i, t_data *data);
t_list		*ft_lock_cmd(char **in_cmd, int i);
char		**ft_lock_trim_cmd(char **in_cmd);
char		**ft_replace(char ***in_cmd, char **in_cmd_2, int n);
void		*ft_resolve_cmd(char **in_cmd, t_data *data);
int			ft_strchar_i(char *in_cmd, char *set);
char		**ft_split_cmd(const char *in_cmd, char *c);
int			ft_word_count(char *in_cmd, char *set, int count);
int			ft_cmd_count(const char *in_cmd, char *set, int c[2]);

long long	ft_atol(char *str, long long *n);
void		*ft_check_ag(char *in_cmd, t_data *data);
int			ft_count_len(char *s1);
t_cmd		*ft_create_cmd(void);
void		ft_search_user(char ***user, char *full, char *ag, char **env);
char		**ft_env_split(char **envp);
char		**ft_extend_split(char **env, char *new_str);
void		ft_free_split(char ***env_split);
char		*ft_get_dir(t_data data);
char		*ft_get_envalue(char *target, char **env, int len);
t_cmd		*ft_redirec_pipe(t_cmd *cmd, char **tmp[2], int *i);
char		*ft_get_prompt(t_data data);
char		*ft_get_user(t_data data);
void		ft_getpid(t_data *data);
t_data		ft_init(t_data data, char *str, char **ag);
t_data		ft_init_data(char **ag, char **envp);
int			ft_n_rows(char **envp);
void		*ft_perror(int error_t, char *str, int error_n);
char		**ft_search_env(char *target, char *val, char **env, int n);
char		**ft_split_all(char **in_cmd, t_data *data);
int			ft_strchr_r(const char *s, int c);
void		ft_update_user(char ***out, int fd);
char		*ft_strtrim_mini(char *S1, int sq, int dq);
int			ft_isspace(char c);
int			ft_count_char(char *str, char c);
int			ft_cmd_env(char **env, int new_line, int fd);
int			ft_env_var(char *ag, char **env, int q[2]);
char		*ft_find_str(char *str);

t_cmd		*ft_get_infile(t_cmd *cmd, char **tmp, int *i);
t_cmd		*ft_get_infile_2(t_cmd *cmd, char **tmp, int *i);
t_cmd		*ft_get_outfile(t_cmd *cmd, char **tmp, int *i);
t_cmd		*ft_get_outfile_2(t_cmd *cmd, char **tmp, int *i);
int			ft_check_dir(char c);
int			ft_getfd(int o_fd, char *path, int f[2]);
int			ft_heredoc(char *str2[2], char *str[2]);
char		*ft_heredoc_2(char *str2[2], size_t len, char *limit, char *warn);
int			ft_cd(t_data *data);
void		ft_cd_error(char **str[2]);
DIR			*ft_check_cmd(t_data *data, t_list *cmd, char ***str, char *path);
int			ft_echo(t_list *cmd);
char		*ft_find_cmd(char **str, char *cmd, char *f_path);
int			ft_pwd(void);
int			ft_exit(t_list *cmd, int *exit_n);
int			ft_export(t_data *data);
t_data		*ft_export_2(t_data *data, char **str, int q[3], int *r_n);
int			ft_exp_error(int q[3], int *r_n);
int			ft_ch_env_name(char *str);
int			ft_unset(t_data *data);
int			ft_cmd_export(t_data *data);

void		*ft_check_fork(t_data *data, t_list *cmd, int fd[2]);
void		ft_fork(t_data *data, t_list *cmd, int fd[2]);
void		ft_fork_2(t_data *data, t_list *cmd, int fd[2]);
void		*ft_fork_3(t_list *cmd, int fd[2]);
void		ft_fork_4(t_data *data, t_cmd *cmd_c, int len, t_list *cmd);
void		ft_get_cmd(t_data *data, t_list *cmd, char **str, char *path);
void		*ft_run_cmd(t_data *data, t_list *cmd);

void		ft_sig_q(int sig);
void		ft_sig_c(int sig);

#endif
