/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:31:00 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 17:37:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*ft_free_cmd(t_list *cmds, char **in_cmd, char **tmp)
{
	ft_lstclear(&cmds, ft_free_fd);
	ft_free_split(&in_cmd);
	ft_free_split(&tmp);
	return (NULL);
}
