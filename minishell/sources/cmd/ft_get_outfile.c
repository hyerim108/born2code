/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:14:56 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:09:07 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_get_outfile(t_cmd *cmd, char **tmp, int *i)
{
	char	*new_line;
	int		f[2];

	f[0] = 1;
	f[1] = 1;
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[++(*i)])
		cmd->output_fd = ft_getfd(cmd->output_fd, tmp[*i], f);
	if (!tmp[*i] || cmd->output_fd == -1)
	{
		*i = -1;
		if (cmd->output_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
		else
			g_status_number = 1;
	}
	return (cmd);
}
