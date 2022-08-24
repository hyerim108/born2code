/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:40:18 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/24 15:38:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msgsend(int num)
{
	static int	power = 0;
	static char	byte = 0;

	if (num == SIGUSR2)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putstr_fd("\033[33m", 1);
		ft_putchar_fd(byte, 1);
		if (byte == 0)
			write(1, "\n", 1);
		power = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("\033[31m[server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	signal(SIGUSR1, msgsend);
	signal(SIGUSR2, msgsend);
	while (1)
		pause();
}
