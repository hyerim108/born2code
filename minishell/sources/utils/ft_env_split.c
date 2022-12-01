/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:54:12 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 18:24:59 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_split(char **envp)
{
	char	**env_split;
	int		i;
	int		n_rows;

	i = 0;
	n_rows = ft_n_rows(envp);
	env_split = malloc(sizeof(char *) * (n_rows + 1));
	if (!env_split)
		return (NULL);
	while (envp[i])
	{
		env_split[i] = ft_strdup(envp[i]);
		if (!env_split[i])
		{
			ft_free_split(&env_split);
			return (NULL);
		}
		i++;
	}
	env_split[i] = NULL;
	return (env_split);
}
