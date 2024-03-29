/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:40:16 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/25 10:24:10 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;	

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
		ft_putstr_fd("ERROR\n", 1);
	else
	{
		while (argv[2][i])
			convert_char(argv[2][i++], pid);
		str_end(pid);
	}
}
