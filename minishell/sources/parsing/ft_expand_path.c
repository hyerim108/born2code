/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:18:48 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/13 15:46:06 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_path(char *in_cmd, int i, int q[2], char *var)
{
	char	*str;
	char	*path;

	q[0] = 0;
	q[1] = 0;
	while (in_cmd && in_cmd[++i])
	{
		q[0] = (q[0] + (!q[1] && in_cmd[i] == '\'')) % 2;
		q[1] = (q[1] + (!q[0] && in_cmd[i] == '\"')) % 2;
		if (!q[0] && !q[1] && in_cmd[i] == '~' && (!i || in_cmd[i - 1] != '$'))
		{
			str = ft_substr(in_cmd, 0, i);
			path = ft_strjoin(str, var);
			free(str);
			str = ft_substr(in_cmd, i + 1, ft_strlen(in_cmd));
			free(in_cmd);
			in_cmd = ft_strjoin(path, str);
			free(path);
			free(str);
			return (ft_expand_path(in_cmd, i + ft_strlen(var) - 1, q, var));
		}
	}
	free(var);
	return (in_cmd);
}
