/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:08 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/01 16:09:44 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo(t_philo *philo)
{
    int i;

    i = -1;
    while (++i < philo->n_philo)
    {
		pthread_mutex_init(&philo->forks[i], NULL);
        philo->philos[i].i = i + 1;
        philo->philos[i].n_eat = 0;
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
	if(!philo->forks)
		return (0);
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