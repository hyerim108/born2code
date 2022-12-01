/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:38:03 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/16 18:17:56 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_fork_4(t_data *data, t_cmd *cmd_c, int len, t_list *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!ft_built(cmd_c) && cmd_c->f_cmd)
		execve(cmd_c->f_path, cmd_c->f_cmd, data->env);
	else if (cmd_c->f_cmd && !ft_strncmp(*cmd_c->f_cmd, "pwd", len)
		&& len == 3)
		g_status_number = ft_pwd();
	else if (cmd_c->f_cmd && ft_built(cmd_c)
		&& !ft_strncmp(*cmd_c->f_cmd, "echo", len) && len == 4)
		g_status_number = ft_echo(cmd);
	else if (cmd_c->f_cmd && ft_built(cmd_c)
		&& !ft_strncmp(*cmd_c->f_cmd, "env", len) && len == 3)
	{
		ft_cmd_env(data->env, 1, 1);
		g_status_number = 0;
	}
}
