/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:21:16 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/15 19:21:20 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_export(t_data *data)
{
	int		q[3];
	int		r_n;
	char	**str;

	q[2] = 1;
	str = ((t_cmd *)data->cmds->content)->f_cmd;
	if (ft_n_rows(str) == 1)
		return (ft_cmd_export(data));
	if (ft_n_rows(str) >= 2)
	{
		q[0] = 1;
		while (str[q[0]])
		{
			r_n = ft_env_var(str[q[0]], data->env, q);
			if (r_n == -1 || ft_ch_env_name(str[q[0]]) || ((!r_n || r_n == 1 \
				|| r_n == -2) && ft_exp_error(q, &r_n) >= 2))
				return (1);
			if ((r_n == -2 && !str[++q[0]]) && q[2] >= 1)
				return (0);
			ft_export_2(data, str, q, &r_n);
			q[0]++;
			q[2]++;
		}
	}
	return (0);
}
