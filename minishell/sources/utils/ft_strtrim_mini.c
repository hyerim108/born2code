/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:49:43 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 13:22:10 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strtrim_mini(char *s1, int sq, int dq)
{
	int		count;
	int		q[2];
	char	*str;

	q[0] = 0;
	q[1] = -1;
	count = ft_count_len(s1);
	if (!s1 || count == -1)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) - count + 1));
	if (!str)
		return (NULL);
	while (s1[q[0]])
	{
		sq = (sq + (!dq && s1[q[0]] == '\'')) % 2;
		dq = (dq + (!sq && s1[q[0]] == '\"')) % 2;
		if ((s1[q[0]] != '\"' || sq) && (s1[q[0]] != '\'' || dq)
			&& ++q[1] >= 0)
			str[q[1]] = s1[q[0]];
		q[0]++;
	}
	str[++q[1]] = '\0';
	return (str);
}
