/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:00 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/01 16:29:19 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_thread
{
	pthread_t		thread;
	int				i;
	int				n_eat;
	long long		time;
	struct s_philo	*all;
}	t_pthread;

typedef struct s_philo
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	long long		time;
	t_pthread		*philos;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
}	t_philo;

/* main */
int		error(char *str, int err);

/* util */
int		ft_atoi(const char *str);
int		check_index(int ac, char **av);
void	ft_usleep(long time);
void	out(t_pthread *pthread, char *str, int x);

/* init */
int		setting_init(t_philo *philo, char **av);
long long	get_time(void);
void	ft_free(t_philo *philo);

/* threads */
void    ft_thread(t_philo *philo);
void    *func(void  *param);

#endif
