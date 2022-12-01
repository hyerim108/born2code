/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:25:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/15 19:20:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env_var(char *ag, char **env, int q[3])
{
	int	i;

	q[1] = 0;
	i = ft_strchr_r(ag, '=');
	if (ag[0] == '=' && q[2] != 3)
		return (-2);
	if (ft_isdigit(ag[0]) && q[2])
	{
		if (q[2] == 1)
			ft_putstr_fd("export: not an identifier\n", 2);
		else if (q[2] < 1)
			ft_putstr_fd("unset: invalid parameter name\n", 2);
		return (-1);
	}
	while (env[q[1]])
	{
		if (!ft_strncmp(env[q[1]], ag, i + 1))
			return (1);
		q[1]++;
	}
	return (0);
}
