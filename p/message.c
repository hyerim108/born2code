#include "philo.h"

void	print_message(t_philo *t, int a, int b)
{
	int		ret;

	pthread_mutex_lock(&t->all->write_m);
	ret = takeoff_time(t->all->start);
	printf("%s%dms %sphilo %d ", KBLU, ret / 1000, KWHT, t->pos);
	if (a == TYPE_EAT)
		printf("%sis eating\n", KGRN);
	if (a == TYPE_SLEEP)
		printf("%sis sleeping\n", KCYN);
	if (a == TYPE_CHOPSTICK)
		printf("%shas taken a chopstick\n", KYEL);
	if (a == TYPE_THINK)
		printf("%sis thinking\n", KMAG);
	if (a == TYPE_DIED)
		printf("%shas died\n", KRED);
	if (a == TYPE_OVER)
		printf("%smust eat count reached\n", KRED);
	if (b)
		pthread_mutex_unlock(&t->all->write_m);
}