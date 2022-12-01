/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_strchar_val.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:09:33 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:21:42 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_strchar_val(char *in_cmd, int i, t_data *data)
{
	char	*str;
	char	*var;
	char	*path;
	int		n;

	n = ft_strchar_i(&in_cmd[i], "|\"\'$?<>") + (ft_strchr("$?", in_cmd[i]) != 0);
	if (n == -1)
		n = ft_strlen(in_cmd) - 1;
	str = ft_substr(in_cmd, 0, i - 1);
	var = ft_get_envalue(&in_cmd[i], data->env,
			ft_strchar_i(&in_cmd[i], "\"\'$|<> "));
	if (!var && in_cmd[i] == '$')
		var = ft_itoa(data->pid);
	else if (!var && in_cmd[i] == '?')
		var = ft_itoa(g_status_number);
	path = ft_strjoin(str, var);
	free(str);
	str = ft_strjoin(path, &in_cmd[i + n]);
	free(var);
	free(path);
	free(in_cmd);
	return (str);
}
