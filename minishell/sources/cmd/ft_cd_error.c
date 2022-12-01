/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:59:42 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 17:59:58 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd_error(char **str[2])
{
	DIR	*dir;

	dir = NULL;
	if (str[0][1])
		dir = opendir(str[0][1]);
	if (!str[0][1] && str[1][0] && !str[1][0][0])
	{
		g_status_number = 1;
		ft_putstr_fd("bash: HOME not set\n", 2);
	}
	if (str[1][0] && !str[0][1])
		g_status_number = chdir(str[1][0]) == -1;
	if (str[0][1] && dir && access(str[0][1], F_OK) != -1)
		chdir(str[0][1]);
	else if (str[0][1] && access(str[0][1], F_OK) == -1)
		ft_perror(NDIR, str[0][1], 1);
	else if (str[0][1])
		ft_perror(NOT_DIR, str[0][1], 1);
	if (str[0][1] && dir)
		closedir(dir);
}
