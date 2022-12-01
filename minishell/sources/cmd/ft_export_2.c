/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:01:36 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 12:05:08 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*ft_export_2(t_data *data, char **str, int q[3], int *r_n)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (*r_n == 1 || *r_n == -2)
	{
		i = 0;
		while (str[q[0]][i])
			if (str[q[0]][i++] == '=')
				f = 1;
		if (f)
		{
			free(data->env[q[1]]);
			data->env[q[1]] = ft_strdup(str[q[0]]);
		}
		else
			return (data);
	}
	else if (!*r_n)
		data->env = ft_extend_split(data->env, str[q[0]]);
	return (data);
}
