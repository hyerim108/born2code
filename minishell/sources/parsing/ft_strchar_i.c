/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:07:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 15:08:18 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strchar_i(char *in_cmd, char *set)
{
	int	i;

	i = 0;
	if (!in_cmd)
		return (-1);
	while (in_cmd[i])
	{
		if (ft_strchr(set, in_cmd[i]))
			return (i);
		i++;
	}
	return (-1);
}
