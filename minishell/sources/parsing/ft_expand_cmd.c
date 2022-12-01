/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:52:53 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:45:57 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_cmd(char *in_cmd, int i, int q[2], t_data *data)
{
	q[0] = 0;
	q[1] = 0;
	while (in_cmd && in_cmd[++i])
	{
		q[0] = (q[0] + (!q[1] && in_cmd[i] == '\'')) % 2;
		q[1] = (q[1] + (!q[0] && in_cmd[i] == '\"')) % 2;
		if (!q[0] && in_cmd[i] == '$' && in_cmd[i + 1]
			&& ((ft_strchar_i(&in_cmd[i + 1], "/~%^{}:; ") && !q[1])
				|| (ft_strchar_i(&in_cmd[i + 1], "/~%^{}:;\"") && q[1])))
			return (ft_expand_cmd(ft_get_strchar_val(in_cmd, ++i, data),
					-1, q, data));
	}
	return (in_cmd);
}
