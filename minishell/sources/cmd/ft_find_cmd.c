/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:14:58 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 11:19:07 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_cmd(char **str, char *cmd, char *f_path)
{
	char	*tmp;
	int		i;

	i = -1;
	f_path = NULL;
	while (str && str[++i])
	{
		free(f_path);
		tmp = ft_strjoin(str[i], "/");
		if (!tmp)
			return (NULL);
		f_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!f_path)
			return (NULL);
		if (!access(f_path, F_OK))
			break ;
	}
	if (!str || !str[i])
	{
		free(f_path);
		return (NULL);
	}
	return (f_path);
}
