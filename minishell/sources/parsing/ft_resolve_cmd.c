/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:46:10 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 13:19:42 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_resolve_cmd(char **in_cmd, t_data *data)
{
	int	exit_n;
	int	cmd_count;

	exit_n = 0;
	data->cmds = ft_lock_cmd(ft_split_all(in_cmd, data), -1);
	if (!data->cmds)
		return (data);
	cmd_count = ft_lstsize(data->cmds);
	g_status_number = ft_built_in(data, data->cmds, &exit_n, 0);
	while (cmd_count-- > 0)
		waitpid(-1, &g_status_number, 0);
	if (g_status_number == 3 || g_status_number == 2)
		g_status_number += 128;
	if (!exit_n && g_status_number == 13)
		g_status_number = 0;
	if (g_status_number > 255)
		g_status_number = g_status_number / 255;
	if (in_cmd && exit_n)
	{
		ft_lstclear(&data->cmds, ft_free_fd);
		return (NULL);
	}
	return (data);
}
