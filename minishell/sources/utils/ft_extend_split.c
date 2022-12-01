/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:22:27 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 18:31:39 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_extend_split(char **env, char *new_str)
{
	char	**env_split;
	int		i;
	int		n_rows;

	i = -1;
	env_split = NULL;
	if (!new_str)
		return (env);
	n_rows = ft_n_rows(env);
	env_split = malloc(sizeof(char *) * (n_rows + 2));
	env_split[n_rows + 1] = NULL;
	if (!env_split)
		return (env);
	while (++i < n_rows)
	{
		env_split[i] = ft_strdup(env[i]);
		if (!env_split[i])
		{
			ft_free_split(&env);
			ft_free_split(&env_split);
		}
	}
	env_split[i] = ft_strdup(new_str);
	ft_free_split(&env);
	return (env_split);
}
