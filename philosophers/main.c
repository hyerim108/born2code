/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:24 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/29 13:36:46 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static int	init_mutex(t_init *init)
{
	int		i;

	i = -1;
	pthread_mutex_init(&init->write_t, NULL);
	pthread_mutex_init(&init->dead_t, NULL);
	pthread_mutex_lock(&init->dead_t);
	init->fork = malloc(sizeof(pthread_mutex_t) * init->n_philo);
	if (!init->fork)
		return (0);
	while (++i < init->n_philo)
		pthread_mutex_init(&init->fork[i], NULL);
	return (1);
}

static int setting(char **av, t_init *init)
{
	init->n_philo = ft_atoi(av[1]);
	init->time_to_die = ft_atoi(av[2]);
	init->time_to_eat = ft_atoi(av[3]);
	init->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		init->n_eat = ft_atoi(av[5]);
	else
		init->n_eat = 0;
	return (1);
}

static int	init(t_init *init)
{
	int		i;

	i = -1;
	
	init->fork = NULL;
	init->philos = malloc(sizeof(t_philo) * init->n_philo);
	if (!init->philos)
		return (0);
	while (++i < init->n_philo)
	{
		init->philos[i].n = i;
		init->philos[i].is_eating = 0;
		init->philos[i].lfork = i;
		init->philos[i].rfork = (i + 1) % init->n_philo;
		init->philos[i].eat_count = 0;
		init->philos[i].all = init;
	}
	return (init_mutex(init));
}

int	main(int ac, char **av)
{
	t_init	*initiz;

	if ((ac != 5 && ac != 6) || !check_index(ac, av))
		return (error("argument Error", 2));
	initiz = malloc(sizeof(t_init));
	if (!setting(av, initiz) || !init(initiz))
		return (ft_error(NULL, "Memory allocation error\n"));
	if (!init_threads(initiz))
		return (ft_error(initiz, "thread create error\n"));
	pthread_mutex_lock(&initiz->dead_t);
	ft_error(initiz, NULL);
	return (0);
}