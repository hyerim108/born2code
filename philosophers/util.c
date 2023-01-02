/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:16 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/02 15:12:21 by hyerimki         ###   ########.fr       */
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
			return (0);
	}
	return (1);
}

int	error(char *str, int err)
{
	printf("%s", str);
	return (err);
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

int	ft_error(t_init *init, char *str)
{
	int	i;

	i = 0;
	if (init)
	{
		pthread_mutex_destroy(&init->dead_t);
		pthread_mutex_destroy(&init->write_t);
		while (i < init->n_philo)
		{
			pthread_mutex_destroy(&init->fork[i]);
			i++;
		}
		free(init->fork);
		free(init);
	}
	if (str)
		error(str, 1);
	return (0);
}

void	ft_sleep(long long time)
{
	long long	t;

	t = get_time();
	while (1)
	{
		if (get_time() - t >= time)
			break ;
		usleep(300);
	}
}
