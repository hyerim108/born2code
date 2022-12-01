/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:59:46 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 13:59:12 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_split(char ***env_split)
{
	int	i;

	i = 0;
	while (env_split && env_split[0] && env_split[0][i])
	{
		free(env_split[0][i]);
		i++;
	}
	if (env_split)
	{
		free(env_split[0]);
		*env_split = NULL;
	}
}
