/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:00 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/26 18:10:49 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# define TYPE_EAT 			0
# define TYPE_SLEEP 		1
# define TYPE_FORK		 	2
# define TYPE_THINK			3
# define TYPE_DIED 			4
# define TYPE_OVER 			5

# define off  "\033[0m"
# define PEO  "\033[0;35m" 
# define RED  "\033[0;31m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define YEL "\033[0;33m"

typedef struct s_philo
{
	int				n;
	int				is_eating;
	struct timeval	max;
	struct timeval	last_eat; //마지막으로 먹은시간
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_init	*all;
	pthread_t		id;
}					t_philo;

typedef struct s_init
{
	int				n_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int				n_eat;

	struct timeval	start; //현재시간

	t_philo			*philos;
	pthread_mutex_t	*fork_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	dead_m;
}					t_init;

/* init.c */
int					init_threads(t_init *init);

/* actions.c */
void				eat(t_philo *p);
void	hold_fork(t_philo *p);
void				put_fork(t_philo *p);

/* print.c */

void				message(t_philo *p, int a, int b);

/* utils.c */

int					ft_atoi(const char *str);
int					ft_error(t_init *init, char *str);
int					ft_strlen(char *str);
int	check_index(int ac, char **av);
int	error(char *str, int err);

/* time.c */
struct timeval		sum_time(struct timeval a, suseconds_t b);
long long		takeoff_time(struct timeval b);
long long			get_time(struct timeval tv);

#endif
