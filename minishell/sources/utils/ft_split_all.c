/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:50:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/19 19:41:03 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_split_all(char **in_cmd, t_data *data)
{
	char	**split_str;
	int		i;
	int		q[2];

	i = -1;
	while (in_cmd && in_cmd[++i])
	{
		in_cmd[i] = ft_expand_cmd(in_cmd[i], -1, q, data);
		in_cmd[i] = ft_expand_path(in_cmd[i], -1, q,
				ft_get_envalue("HOME", data->env, 4));
		split_str = ft_cmd_split(in_cmd[i], "<>|");
		ft_replace(&in_cmd, split_str, i);
		i += ft_n_rows(split_str) - 1;
		ft_free_split(&split_str);
	}
	return (in_cmd);
}
