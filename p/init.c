
#include "philo.h"

static void	*monitor_count(void *phi)
{
	t_state			*p;
	int				i;

	p = (t_state *)phi;
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
			print_message(&p->philos[0], TYPE_OVER, 0);
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
		if (!t->is_eating && get_time(t->limit) < get_time(ctime))
		{
			print_message(t, TYPE_DIED, 0);
			pthread_mutex_unlock(&t->all->dead_m);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}

static void	*routine(void *phi)
{
	t_philo		*t;
	pthread_t	id;

	t = (t_philo *)phi;
	t->last_meal = t->all->start;
	t->limit = sum_time(t->last_meal, t->all->time_to_die * 1000);
	pthread_create(&id, NULL, &monitor, phi);
	pthread_detach(id);
	while (1)
	{
		pick_chopsticks(t);
		eat(t);
		leave_chopsticks(t);
	}
	return (NULL);
}

int	init_threads(t_state *p)
{
	int			i;
	void		*phi;
	pthread_t	id;

	i = -1;
	gettimeofday(&(p->start), NULL);
	// if (p->meals)
	// {
	// 	pthread_create(&id, NULL, monitor_count, (void *)p);
	// 	pthread_detach(id);
	// }	
	while (++i < p->n_philo)
	{
		phi = (void *)(&p->philos[i]);
		if (pthread_create(&p->philos[i].id, NULL, routine, phi))
			return (0);
		pthread_detach(p->philos[i].id);
		usleep(100);
	}
	return (1);
}