/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:54:24 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 12:06:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_run_cmd(t_data *data, t_list *cmd)
{
	int	fd[2];

	ft_get_cmd(data, cmd, NULL, NULL);
	if (pipe(fd) == -1)
		return (ft_perror(PIPERR, NULL, 1));
	if (!ft_check_fork(data, cmd, fd))
		return (NULL);
	close(fd[WRITE_END]);
	if (cmd->next && !((t_cmd *)cmd->next->content)->input_fd)
		((t_cmd *)cmd->next->content)->input_fd = fd[READ_END];
	else
		close(fd[READ_END]);
	if (((t_cmd *)cmd->content)->input_fd > 2)
		close(((t_cmd *)cmd->content)->input_fd);
	if (((t_cmd *)cmd->content)->output_fd > 2)
		close(((t_cmd *)cmd->content)->output_fd);
	return (NULL);
}
