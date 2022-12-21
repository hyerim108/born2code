
#include "philo.h"

void	pick_chopsticks(t_philo *t)
{
	pthread_mutex_lock(&t->all->fork_m[t->lfork]);
	print_message(t, TYPE_CHOPSTICK, 1);
	pthread_mutex_lock(&t->all->fork_m[t->rfork]);
	print_message(t, TYPE_CHOPSTICK, 1);
}

void	eat(t_philo *t)
{
	t->is_eating = 1;
	print_message(t, TYPE_EAT, 1);
	gettimeofday(&t->last_meal, NULL);
	t->limit = sum_time(t->last_meal, t->all->time_to_die * 1000);
	t->eat_count++;
	usleep(t->all->time_to_eat * 1000);
	t->is_eating = 0;
}

void	leave_chopsticks(t_philo *t)
{
	pthread_mutex_unlock(&t->all->fork_m[t->lfork]);
	pthread_mutex_unlock(&t->all->fork_m[t->rfork]);
	print_message(t, TYPE_SLEEP, 1);
	usleep(t->all->time_to_sleep * 1000);
	print_message(t, TYPE_THINK, 1);
}