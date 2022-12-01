/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:43:33 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 11:46:13 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_env(char **env, int new_line, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (env && env[i])
	{
		if (new_line)
			count += ft_putendl_fd(env[i], fd);
		else
			count += ft_putstr_fd(env[i], fd);
		i++;
	}
	return (count);
}
