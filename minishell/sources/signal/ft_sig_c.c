/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:27:15 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 15:06:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sig_c(int sig)
{
	if (sig == SIGINT)
	{
		g_status_number = 1;
		rl_on_new_line();
		rl_redisplay();
		write(2, "  ", 2);
		write(2, "\b\b", 2);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
