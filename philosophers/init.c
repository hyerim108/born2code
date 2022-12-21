/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:08 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/21 21:18:26 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->n_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		philo->philos[i].i = i + 1;
		philo->philos[i].n_eat = 0;
		philo->philos[i].left = i;
		philo->philos[i].rignt = (i + 1) % philo->n_philo;
		philo->philos[i].time = philo->time;
		philo->philos[i].all = philo;
	}
}

int	setting_init(t_philo *philo, char **av)
{
	philo->n_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]);
	philo->philos = malloc(sizeof(t_pthread) * (philo->n_philo));
	if (!philo->philos)
		return (0);
	philo->forks = malloc(sizeof(pthread_mutex_t) * (philo->n_philo));
	if (!philo->forks)
		return (free(philo->philos),0);
	philo->time = get_time();
	init_philo(philo);
	return (1);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->n_philo)
		pthread_mutex_destroy(&(philo->forks[i]));
	pthread_mutex_destroy(&(philo->mutex));
	free(philo->philos);
	free(philo->forks);
}

void	*ft_die(t_philo *philo)
{
	int	i;
	int x;
	x = 0;
	i = 0;
	while (1)
	{
		//ㅂㅏㅇ어하기
		if (i == philo->n_philo)
		{
			i = 0;
			x = 0;
		}
		if (philo->n_eat)
		{
			if (ft_check_eat(&philo->n_eat))
				break;
		}
			// if (!check_eat(&x, &philo->philos[i]))
			// 	break ;
		if ((get_time() - philo->philos[i].time) > philo->time_to_die)
		{
			out(&philo->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
int	ft_check_eat(int *eat)
{
	if (*eat == -1)
		return (1);
	else if (*eat == 0)
		return (0);
	else
		return (--(*eat) + 1);
}