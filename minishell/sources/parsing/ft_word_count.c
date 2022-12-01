/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:28:05 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:48:16 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_word_count(char *in_cmd, char *set, int count)
{
	int	q[2];
	int	i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (in_cmd && in_cmd[i])
	{
		count++;
		if (!ft_strchr(set, in_cmd[i]))
		{
			while ((!ft_strchr(set, in_cmd[i]) || q[0]
					|| q[1]) && in_cmd[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && in_cmd[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && in_cmd[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}
