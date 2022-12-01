/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:33:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:35:24 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_fd(void *content)
{
	t_cmd	*cmd;

	cmd = content;
	ft_free_split(&cmd->f_cmd);
	free(cmd->f_path);
	if (cmd->input_fd != STDIN_FILENO)
		close(cmd->input_fd);
	if (cmd->output_fd != STDOUT_FILENO)
		close(cmd->output_fd);
	free(cmd);
}
