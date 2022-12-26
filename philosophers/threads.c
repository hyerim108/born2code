/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:09 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/26 19:52:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor_count(void *phi)
{
	t_init			*p;
	int				i;

	p = (t_init *)phi;
	while (1)
	{
		i = 0;
		while (i < p->n_philo)
		{
			if (p->philos[i].eat_count >= p->n_eat)
				i++;
			else
				break ;
		}
		if (i == p->n_philo)
		{
			message(&p->philos[0], TYPE_OVER, 0);
			pthread_mutex_unlock(&p->dead_m);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

static void	*monitor(void *phi)
{
	t_philo			*t;
	struct timeval	ctime;

	t = (t_philo *)phi;
	while (1)
	{
		gettimeofday(&ctime, NULL);
		if (!t->is_eating && get_time(t->max) < get_time(ctime))
		{
			message(t, TYPE_DIED, 0);
			pthread_mutex_unlock(&t->all->dead_m);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}

static void	*func(void *phi)
{
	t_philo		*t;
	pthread_t	id;

	t = (t_philo *)phi;
	t->last_eat = t->all->start; //마지막으로 먹은시간을 저장
	t->max = sum_time(t->last_eat, t->all->time_to_die * 1000);
	pthread_create(&id, NULL, &monitor, phi);
	pthread_detach(id);
	while (1)
	{
		hold_fork(t);
		eat(t);
		put_fork(t);
	}
	return (NULL);
}

int	init_threads(t_init *init)
{
	int			i;
	void		*phi;
	pthread_t	id;

	i = -1;
	gettimeofday(&(init->start), NULL);
	if (init->n_eat)
	{
		pthread_create(&id, NULL, monitor_count, (void *)init);
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
