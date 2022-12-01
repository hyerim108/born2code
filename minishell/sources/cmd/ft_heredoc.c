/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:35:59 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 16:46:25 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_heredoc(char *str2[2], char *str[2])
{
	int	fd[2];

	g_status_number = 0;
	if (pipe(fd) == -1)
	{
		ft_perror(PIPERR, NULL, 1);
		return (-1);
	}
	str2[1] = ft_heredoc_2(str2, 0, str[0], str[1]);
	write(fd[WRITE_END], str2[1], ft_strlen(str2[1]));
	free(str2[1]);
	close(fd[WRITE_END]);
	if (g_status_number == 1)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}
