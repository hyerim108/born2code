/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:16 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/29 13:37:10 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	error(char *str, int err)
{
	printf("%s", str);
	return (err);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	n = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result >= 2147483648 && n == 1)
			return (-1);
		else if (result >= 2147483649 && n == -1)
			return (0);
		result *= 10;
		result += str[i++] - 48;
	}
	return (result * n);
}

static void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_error(t_init *init, char *str)
{
	int	i;

	i = 0;
	if (init)
	{
		pthread_mutex_destroy(&init->dead_t);
		pthread_mutex_destroy(&init->write_t);
		while (i < init->n_philo)
		{
			pthread_mutex_destroy(&init->fork[i]);
			i++;
		}
		free(init->fork);
		free(init);
	}
	if (str)
		ft_putendl_fd(str, 1);
	return (0);
}