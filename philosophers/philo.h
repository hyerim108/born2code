/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:00 by hyerimki          #+#    #+#             */
/*   Updated: 2022/10/21 18:33:06 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_thread
{
	pthread_t	philo;
}	t_pthread;

typedef struct s_philo
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	t_pthread		*philos;
}	t_philo;

/* main */
int	error(char *str, int err);

/* util */
int	ft_atoi(const char *str);
int	check_index(int ac, char **av);

#endif
