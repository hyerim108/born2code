/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:52:29 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 16:19:58 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(t_list *cmd)
{
	int		new_line;
	int		q[2];
	char	**str;
	t_cmd	*cmd_c;

	q[0] = 0;
	q[1] = 0;
	new_line = 1;
	cmd_c = cmd->content;
	str = cmd_c->f_cmd;
	while (str && str[++q[0]])
	{
		if (!q[1] && !ft_strncmp(str[q[0]], "-n", 2) && \
			(ft_count_char(str[q[0]], 'n') == (int)(ft_strlen(str[q[0]]) - 1)))
			new_line = 0;
		else
		{
			q[1] = 1;
			ft_putstr_fd(str[q[0]], 1);
			if (str[q[0] + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	return (write(1, "\n", new_line) == 2);
}
