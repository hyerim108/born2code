/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:00 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/29 18:18:41 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# define EAT 			0
# define SLEEP 			1
# define FORK		 	2
# define THINK			3
# define DIED 			4
# define OVER 			5

# define WHI  "\033[0m"
# define PEO  "\033[0;35m" 
# define RED  "\033[0;31m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define YEL "\033[0;33m"

typedef struct s_philo
{
	int				n;
	int				is_eating;
	int				lfork;
	int				rfork;
	long long		time;
	int				eat_count;
	struct s_init	*all;
	pthread_t		id;
}					t_philo;

typedef struct s_init
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	long long		main_start;

	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_t;
	pthread_mutex_t	dead_t;
}					t_init;

/* init.c */
int					init_threads(t_init *init);

/* actions.c */
void				eat(t_philo *p);
void				hold_fork(t_philo *p);
void				put_fork(t_philo *p);
long long			get_time(void);
/* print.c */

void				message(t_philo *p, int a, int b);

/* utils.c */

int					ft_atoi(const char *str);
int					ft_error(t_init *init, char *str);
int					ft_strlen(char *str);
int					check_index(int ac, char **av);
int					error(char *str, int err);

#endif
