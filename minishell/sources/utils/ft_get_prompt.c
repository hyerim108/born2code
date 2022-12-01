/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:44:11 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/11 17:46:21 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_prompt(t_data data)
{
	char	*tmp;
	char	*tmp2;
	char	*dir;

	tmp = ft_get_user(data);
	tmp2 = ft_strjoin(tmp, "");
	free(tmp);
	dir = ft_get_dir(data);
	tmp = ft_strjoin(tmp2, dir);
	free(dir);
	free(tmp2);
	tmp2 = ft_strjoin(tmp, RED);
	free(tmp);
	tmp = ft_strjoin(tmp2, "% ");
	free(tmp2);
	tmp2 = ft_strjoin(tmp, DEFAULT);
	free(tmp);
	return (tmp2);
}
