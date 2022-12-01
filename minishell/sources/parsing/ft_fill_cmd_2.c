/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cmd_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:59:37 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:46:44 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_fill_cmd_2(char **str, const char *in_cmd, char *c, int q[3])
{
	int	len;
	int	q_2[2];

	q_2[0] = 0;
	q_2[1] = 0;
	len = ft_strlen(in_cmd);
	while (in_cmd[q[0]])
	{
		while (ft_strchr(c, in_cmd[q[0]]) && in_cmd[q[0]])
			q[0]++;
		q[1] = q[0];
		while ((!ft_strchr(c, in_cmd[q[0]])
				|| q_2[0] || q_2[1]) && in_cmd[q[0]])
		{
			q_2[0] = (q_2[0] + (!q_2[1] && in_cmd[q[0]] == '\'')) % 2;
			q_2[1] = (q_2[1] + (!q_2[0] && in_cmd[q[0]] == '\"')) % 2;
			q[0]++;
		}
		if (q[1] >= len)
			str[q[2]++] = "\0";
		else
			str[q[2]++] = ft_substr(in_cmd, q[1], q[0] - q[1]);
	}
	return (str);
}
