/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:05:23 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 18:33:36 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_perror(int error_t, char *str, int error_n)
{
	g_status_number = error_n;
	if (error_t == QUOTE)
		printf("quote: you need to pair single or double quote\n");
	else if (error_t == NDIR)
		printf("bash: no such file or directory: ");
	else if (error_t == NPERM)
		printf("bash: permission denied: ");
	else if (error_t == PIPERR)
		printf("bash: pipe error\n");
	else if (error_t == FORKERR)
		printf("bash: fork error\n");
	else if (error_t == ISDIR)
		printf("bash: is a directory: ");
	else if (error_t == NOT_DIR)
		printf("bash: not a directory: ");
	else if (error_t == DUPERR)
		printf("bash: dup2 error\n");
	else if (error_t == NCMD)
		printf("bash: command not found: ");
	if (str)
		printf("%s\n", str);
	return (0);
}
