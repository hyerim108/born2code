/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:25:42 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:49:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_count(const char *in_cmd, char *set, int c[2])
{
	int	arr[2];

	arr[0] = 0;
	arr[1] = 0;
	while (in_cmd[c[0]])
	{
		if (!ft_strchr(set, in_cmd[c[0]]))
		{
			c[1]++;
			while ((!ft_strchr(set, in_cmd[c[0]])
					|| arr[0]) && in_cmd[c[0]] != '\0')
			{
				if (!arr[1] && (in_cmd[c[0]] == '\"' || in_cmd[c[0]] == '\''))
					arr[1] = in_cmd[c[0]];
				arr[0] = (arr[0] + (in_cmd[c[0]] == arr[1])) % 2;
				arr[1] *= arr[0] != 0;
				c[0]++;
			}
			if (arr[0])
				return (-1);
		}
		else
			c[0]++;
	}
	return (c[1]);
}
