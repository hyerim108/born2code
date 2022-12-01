/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:51:09 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/12 11:49:25 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	ft_init_data(char **ag, char **envp)
{
	t_data	data;
	char	*str;

	data.cmds = NULL;
	data.env = ft_env_split(envp);
	str = NULL;
	g_status_number = 0;
	ft_getpid(&data);
	data = ft_init(data, str, ag);
	return (data);
}
