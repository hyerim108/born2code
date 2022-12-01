/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:56:50 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 18:39:44 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sig_q(int sig)
{
	if (sig == SIGQUIT)
	{
		g_status_number = 131;
		rl_redisplay();
		write(2, "  ", 2);
		write(2, "\b\b", 2);
	}
}
