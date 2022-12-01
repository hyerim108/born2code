/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:24:49 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:11:23 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_cmd_split(char *in_cmd, char *set)
{
	char	**str;
	int		w_c;
	int		q[3];

	q[0] = 0;
	q[1] = 0;
	q[2] = 0;
	if (!in_cmd)
		return (NULL);
	w_c = ft_word_count(in_cmd, set, 0);
	if (w_c == -1)
		return (NULL);
	str = malloc(sizeof(char *) * (w_c + 1));
	if (!str)
		return (NULL);
	str = ft_fill_cmd(str, in_cmd, set, q);
	str[w_c] = NULL;
	return (str);
}
