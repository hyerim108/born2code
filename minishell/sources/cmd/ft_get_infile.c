/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:23:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:45:15 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_get_infile(t_cmd *cmd, char **tmp, int *i)
{
	char	*str[2];
	char	*str2[2];
	char	*new_line;

	str2[0] = NULL;
	str2[1] = NULL;
	str[0] = NULL;
	str[1] = "bash: warning: heredocument delimited by EOF";
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[++(*i)])
	{
		str[0] = tmp[*i];
		cmd->input_fd = ft_heredoc(str2, str);
	}
	if (!tmp[*i] || cmd->input_fd == -1)
	{
		*i = -1;
		if (cmd->input_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
	}
	return (cmd);
}
