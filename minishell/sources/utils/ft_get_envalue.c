/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:32:37 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 12:35:32 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_envalue(char *target, char **env, int len)
{
	int	i;
	int	len_2;

	i = 0;
	if (len < 0)
		len = ft_strlen(target);
	while (env && env[i] && !ft_strchr(target, '='))
	{
		len_2 = len;
		if (len_2 < ft_strchr_r(env[i], '='))
			len_2 = ft_strchr_r(env[i], '=');
		if (!ft_strncmp(env[i], target, len_2))
			return (ft_substr(env[i], len_2 + 1, ft_strlen(env[i])));
		i++;
	}
	return (NULL);
}
