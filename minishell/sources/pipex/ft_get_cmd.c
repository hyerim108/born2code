/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:55:52 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 13:05:36 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_get_cmd(t_data *data, t_list *cmd, char **str, char *path)
{
	t_cmd	*cmd_c;
	DIR		*dir;

	cmd_c = cmd->content;
	dir = ft_check_cmd(data, cmd, &str, path);
	if (cmd_c && cmd_c->f_cmd && !ft_built(cmd_c) && dir)
		ft_perror(ISDIR, *cmd_c->f_cmd, 126);
	else if (cmd_c && cmd_c->f_path && !ft_built(cmd_c)
		&& access(cmd_c->f_path, F_OK) == -1)
		ft_perror(NDIR, cmd_c->f_path, 127);
	else if (cmd_c && cmd_c->f_path && !ft_built(cmd_c)
		&& access(cmd_c->f_path, X_OK) == -1)
		ft_perror(NPERM, cmd_c->f_path, 126);
	if (dir)
		closedir(dir);
	ft_free_split(&str);
}
