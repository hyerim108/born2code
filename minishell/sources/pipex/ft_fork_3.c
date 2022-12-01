/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:32:19 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 12:04:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_fork_3(t_list *cmd, int fd[2])
{
	t_cmd	*cmd_c;

	cmd_c = cmd->content;
	if (cmd_c->input_fd != STDIN_FILENO)
	{
		if (dup2(cmd_c->input_fd, STDIN_FILENO) == -1)
			return (ft_perror(DUPERR, NULL, 1));
		close(cmd_c->input_fd);
	}
	if (cmd_c->output_fd != STDOUT_FILENO)
	{
		if (dup2(cmd_c->output_fd, STDOUT_FILENO) == -1)
			return (ft_perror(DUPERR, NULL, 1));
		close(cmd_c->output_fd);
	}
	else if (cmd->next && dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		return (ft_perror(DUPERR, NULL, 1));
	close(fd[WRITE_END]);
	return ("");
}
