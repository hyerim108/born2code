/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:29:17 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:45:41 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_data *data)
{
	char	**ag;
	char	*str;
	int		q[3];

	q[0] = 0;
	q[2] = 2;
	ag = ((t_cmd *)data->cmds->content)->f_cmd;
	if (ft_n_rows(ag) >= 2)
	{
		while (ag[++q[0]])
		{
			if (ag[q[0]][ft_strlen(ag[q[0]]) - 1] != '=')
			{
				str = ft_strjoin(ag[q[0]], "=");
				free(ag[q[0]]);
				ag[q[0]] = str;
			}
			if (ft_env_var(ag[q[0]], data->env, q) != -1)
				ft_replace(&data->env, NULL, q[1]);
			else
				return (1);
		}
	}
	return (0);
}
