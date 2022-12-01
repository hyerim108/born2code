/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:10:39 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 12:39:26 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	ft_init(t_data data, char *str, char **ag)
{
	char	*num;

	str = getcwd(NULL, 0);
	data.env = ft_search_env("PWD", str, data.env, 3);
	free(str);
	str = ft_get_envalue("SHLVL", data.env, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	data.env = ft_search_env("SHLVL", num, data.env, 5);
	free(num);
	str = ft_get_envalue("PATH", data.env, 4);
	if (!str)
		data.env = ft_search_env("PATH",
				"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", data.env, 4);
	free(str);
	str = ft_get_envalue("_", data.env, 1);
	if (!str)
		data.env = ft_search_env("_", ag[0], data.env, 1);
	free(str);
	return (data);
}
