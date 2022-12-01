/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:18:38 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 13:11:43 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_check_ag(char *in_cmd, t_data *data)
{
	char	**str;
	t_cmd	*cmd;

	if (!in_cmd)
	{
		printf("exit\n");
		return (NULL);
	}
	if (in_cmd[0])
		add_history(in_cmd);
	str = ft_split_cmd(in_cmd, " ");
	free(in_cmd);
	if (!str)
		ft_perror(QUOTE, NULL, 1);
	if (!str)
		return ("");
	data = ft_resolve_cmd(str, data);
	if (data && data->cmds)
		cmd = data->cmds->content;
	if (data && data->cmds && cmd->f_cmd && ft_lstsize(data->cmds) == 1)
		data->env = ft_search_env("_", cmd->f_cmd[ft_n_rows(cmd->f_cmd) - 1],
				data->env, 1);
	if (data && data->cmds)
		ft_lstclear(&data->cmds, ft_free_fd);
	return (data);
}
