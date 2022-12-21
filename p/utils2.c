#include "philo.h"
int	check_index(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) < 1 || ft_atoi(av[i]) > 2147483647)
			return (error("parsing error", 2));
	}
	return (1);
}
int	init_mutex(t_state *p)
{
	int		i;

	i = -1;
	pthread_mutex_init(&p->write_m, NULL);
	pthread_mutex_init(&p->dead_m, NULL);
	pthread_mutex_lock(&p->dead_m);
	p->fork_m = malloc(sizeof(pthread_mutex_t) * p->n_philo);
	if (!p->fork_m)
		return (0);
	while (++i < p->n_philo)
		pthread_mutex_init(&p->fork_m[i], NULL);
	return (1);
}

int	init(t_state *p)
{
	int		i;

	i = -1;
	p->fork_m = NULL;
	p->philos = malloc(sizeof(t_philo) * p->n_philo);
	if (!p->philos)
		return (0);
	while (++i < p->n_philo)
	{
		p->philos[i].pos = i;
		p->philos[i].is_eating = 0;
		p->philos[i].lfork = i;
		p->philos[i].rfork = (i + 1) % p->n_philo;
		p->philos[i].eat_count = 0;
		p->philos[i].all = p;
	}
	return (init_mutex(p));
}

int	setting_init(t_state *philo, char **av)
{
	philo = malloc(sizeof(t_state));
	philo->n_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->n_eat = ft_atoi(av[5]);
	else
		philo->n_eat = 0;
	if (!init(philo))
		return (ft_error(NULL, "Memory allocation error\n"));
	if (!init_threads(philo))
		return (ft_error(philo, "Unexpected error\n"));
	pthread_mutex_lock(&philo->dead_m);
	return (1);
}