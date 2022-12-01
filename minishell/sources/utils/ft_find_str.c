/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:11:36 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/15 19:19:51 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_str(char *str)
{
	int		i;
	char	*r_str;

	i = 0;
	r_str = NULL;
	while (str[i])
	{
		if (str[i] == '=')
		{
			r_str = ft_substr(str, 0, i);
			break ;
		}
		i++;
	}
	return (r_str);
}
