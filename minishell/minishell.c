/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:40:44 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 19:13:42 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **ag, char **envp)
{
	char	*str;
	char	*out;
	t_data	data;

	(void)ac;
	data = ft_init_data(ag, envp);
	while (1)
	{
		signal(SIGINT, ft_sig_c);
		signal(SIGQUIT, SIG_IGN);
		str = ft_get_prompt(data);
		if (str)
			out = readline(str);
		else
			out = readline("minishell $ ");
		free(str);
		if (!ft_check_ag(out, &data))
			break ;
	}
	exit(g_status_number);
}
