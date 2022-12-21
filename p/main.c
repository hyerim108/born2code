#include "philo.h"

int	error(char *str, int err)
{
	printf("%s", str);
	return (err);
}

int	main(int ac, char **av)
{
	t_state	*philo;

	if ((ac != 5 && ac != 6) || !check_index(ac, av))
		return (error("argument Error", 2));
	if (!setting_init(philo, av))
		return (error("allocation Error", 2));
	ft_error(philo, NULL);
	return (0);
}