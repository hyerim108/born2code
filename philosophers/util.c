/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:16 by hyerimki          #+#    #+#             */
/*   Updated: 2022/10/21 18:31:43 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_index(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) < 1 || ft_atoi(av[i]) > 2147483647)
			return (error("argument_size error", 2));
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= 2147483648 && n == 1)
			return (-1);
		else if (result >= 2147483649 && n == -1)
			return (0);
		result *= 10;
		result += str[i++] - 48;
	}
	return (result * n);
}
