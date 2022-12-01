/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infile_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:28:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:45:24 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_get_infile_2(t_cmd *cmd, char **tmp, int *i)
{
	char	*new_line;
	int		f[2];

	f[0] = 0;
	f[1] = 1;
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[*i])
		cmd->input_fd = ft_getfd(cmd->input_fd, tmp[*i], f);
	if (!tmp[*i] || cmd->input_fd == -1)
	{
		*i = -1;
		if (cmd->input_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
		else
			g_status_number = 1;
	}
	return (cmd);
}
