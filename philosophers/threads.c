/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:09 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/29 18:34:10 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*die_check(void *phi)
{
	t_init			*init;
	int				i;

	init = (t_init *)phi;
	while (1)
	{
		i = 0;
		while (i < init->n_philo)
		{
			if (init->philos[i].eat_count >= init->n_eat)
				i++;
			else
				break ;
		}
		if (i == init->n_philo)
		{
			message(&init->philos[0], OVER, 0);
			pthread_mutex_unlock(&init->dead_t);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

static void	*monitor(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (!philo->is_eating && get_time()- philo->time > philo->all->time_to_die)
		{
			message(philo, DIED, 0);
			pthread_mutex_unlock(&philo->all->dead_t);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}

static void	*func(void *t)
{
	t_philo		*philo;
	pthread_t	id;
	
	philo = (t_philo *)t;
	philo->time = philo->all->main_start;
	pthread_create(&id, NULL, &monitor, philo);
	pthread_detach(id);
	while (1)
	{
		hold_fork(philo);
		eat(philo);
		put_fork(philo);
	}
	return (NULL);
}

int	init_threads(t_init *init)
{
	int			i;
	void		*phi;
	pthread_t	id;

	i = -1;
	init->main_start = get_time();
	if (init->n_eat)
	{
		pthread_create(&id, NULL, die_check, (void *)init);
		pthread_detach(id);
	}
	while (++i < init->n_philo)
	{
		phi = (void *)(&init->philos[i]);
		if (pthread_create(&init->philos[i].id, NULL, func, phi))
			return (0);
		pthread_detach(init->philos[i].id);
		usleep(100);
	}
	return (1);
}
