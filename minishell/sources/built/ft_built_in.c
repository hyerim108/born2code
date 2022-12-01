/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:36:33 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 13:43:30 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_built_in(t_data *data, t_list *cmd, int *exit_n, int n)
{
	char	**str;

	while (cmd)
	{
		str = ((t_cmd *)cmd->content)->f_cmd;
		n = 0;
		if (str)
			n = ft_strlen(*str);
		if (str && !ft_strncmp(*str, "exit", n) && n == 4)
			g_status_number = ft_exit(cmd, exit_n);
		g_status_number = ft_built_in_2(data, cmd, str, n);
		cmd = cmd->next;
	}
	return (g_status_number);
}
