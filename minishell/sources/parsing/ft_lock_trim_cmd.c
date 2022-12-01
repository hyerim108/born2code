/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_trim_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:27:18 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:29:10 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_lock_trim_cmd(char **in_cmd)
{
	char	**str;
	char	*tmp;
	int		i;

	i = -1;
	str = ft_env_split(in_cmd);
	while (str && str[++i])
	{
		tmp = ft_strtrim_mini(str[i], 0, 0);
		free(str[i]);
		str[i] = tmp;
	}
	return (str);
}
