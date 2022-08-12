/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:40:18 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/12 15:30:27 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msgsend(int num)
{
	int	power;
	int	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar_fd(byte, 1);
		power = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	signal(SIGUSR1, msgsend);
	signal(SIGUSR2, msgsend);
	while (1)
		pause();
}
