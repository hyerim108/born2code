/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:24:44 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 13:02:50 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_check_fork(t_data *data, t_list *cmd, int fd[2])
{
	t_cmd	*cmd_c;
	DIR		*dir;

	cmd_c = cmd->content;
	dir = NULL;
	if (cmd_c->f_cmd)
		dir = opendir(*cmd_c->f_cmd);
	if (cmd_c->input_fd == -1 || cmd_c->output_fd == -1)
		return (NULL);
	if ((cmd_c->f_path && !access(cmd_c->f_path, X_OK)) || ft_built(cmd_c))
		ft_fork(data, cmd, fd);
	else if (!ft_built(cmd_c) && ((cmd_c->f_path
				&& !access(cmd_c->f_path, F_OK)) || dir))
		g_status_number = 126;
	else if (!ft_built(cmd_c) && cmd_c->f_cmd)
		g_status_number = 127;
	if (dir)
		closedir(dir);
	return ("");
}
