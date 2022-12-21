#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		nb;

	i = 0;
	neg = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		nb = nb * (-1);
	return (nb);
}

// Habrá que hacer una función distinta cuando haya que matar mutex

static void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(t_state *p, char *str)
{
	int	i;

	i = 0;
	if (p)
	{
		pthread_mutex_destroy(&p->dead_m);
		pthread_mutex_destroy(&p->write_m);
		while (i < p->n_philo)
		{
			pthread_mutex_destroy(&p->fork_m[i]);
			i++;
		}
		free(p->fork_m);
		free(p);
	}
	if (str)
		ft_putendl_fd(str, 1);
	return (0);
}