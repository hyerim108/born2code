/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:08:58 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 12:48:54 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built(t_cmd *cmd)
{
	int	len;

	if (!cmd->f_cmd)
		return (0);
	if ((cmd->f_cmd && ft_strchr(*cmd->f_cmd, '/')) || (cmd->f_path
			&& ft_strchr((char *)cmd->f_path, '/')))
		return (0);
	len = ft_strlen(*cmd->f_cmd);
	if (!ft_strncmp(*cmd->f_cmd, "pwd", len) && len == 3)
		return (1);
	if (!ft_strncmp(*cmd->f_cmd, "cd", len) && len == 2)
		return (1);
	if (!ft_strncmp(*cmd->f_cmd, "echo", len) && len == 4)
		return (1);
	if (!ft_strncmp(*cmd->f_cmd, "unset", len) && len == 5)
		return (1);
	if (!ft_strncmp(*cmd->f_cmd, "exit", len) && len == 4)
		return (1);
	if (!ft_strncmp(*cmd->f_cmd, "export", len) && len == 6)
		return (1);
	if (!ft_strncmp(*cmd->f_cmd, "env", len) && len == 3)
		return (1);
	return (0);
}
