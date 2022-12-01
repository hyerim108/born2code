/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:39:58 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/16 18:27:07 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_heredoc_2(char *str2[2], size_t len, char *limit, char *warn)
{
	char	*tmp;

	(void)warn;
	while (g_status_number != 1 && (!str2[0]
			|| ft_strncmp(str2[0], limit, len)
			|| ft_strlen(limit) != len))
	{
		tmp = str2[1];
		str2[1] = ft_strjoin(str2[1], str2[0]);
		free(tmp);
		free(str2[0]);
		str2[0] = readline("> ");
		if (!str2[0])
			break ;
		tmp = str2[0];
		str2[0] = ft_strjoin(str2[0], "\n");
		free(tmp);
		len = ft_strlen(str2[0]) - 1;
	}
	free(str2[0]);
	return (str2[1]);
}
