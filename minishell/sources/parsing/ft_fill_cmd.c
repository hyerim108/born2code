/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:33:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:46:32 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_fill_cmd(char **str, const char *in_cmd, char *set, int q[3])
{
	int	q_2[2];

	q_2[0] = 0;
	q_2[1] = 0;
	while (in_cmd && in_cmd[q[0]])
	{
		q[1] = q[0];
		if (!ft_strchr(set, in_cmd[q[0]]))
		{
			while ((!ft_strchr(set, in_cmd[q[0]])
					|| q_2[0] || q_2[1]) && in_cmd[q[0]])
			{
				q_2[0] = (q_2[0] + (!q_2[1] && in_cmd[q[0]] == '\'')) % 2;
				q_2[1] = (q_2[1] + (!q_2[0] && in_cmd[q[0]] == '\"')) % 2;
				q[0]++;
			}
		}
		else
			q[0]++;
		str[q[2]++] = ft_substr(in_cmd, q[1], q[0] - q[1]);
	}
	return (str);
}
