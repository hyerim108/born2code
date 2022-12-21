#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# define TYPE_EAT 			0
# define TYPE_SLEEP 		1
# define TYPE_CHOPSTICK 	2
# define TYPE_THINK			3
# define TYPE_DIED 			4
# define TYPE_OVER 			5

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_philo
{
	int				pos;
	int				is_eating;
	struct timeval	limit;
	struct timeval	last_meal;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_state	*all;
	pthread_t		id;
}					t_philo;

typedef struct s_state
{
	int				n_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int				n_eat;

	struct timeval	start;

	t_philo			*philos;
	pthread_mutex_t	*fork_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	dead_m;
}					t_state;

int	setting_init(t_state *philo, char **av);
int	init(t_state *p);
int	init_mutex(t_state *p);
/*
**	init.c
*/
int					init_threads(t_state *p);

/*
**	actions.c
*/
void				eat(t_philo *t);
void				pick_chopsticks(t_philo *t);
void				leave_chopsticks(t_philo *t);

/*
**	message.c
*/
void				print_message(t_philo *t, int a, int b);
/*
**	utils.c
*/
int					ft_atoi(const char *str);
int					ft_error(t_state *p, char *str);
int					ft_strlen(char *str);

/*
**	time.c
*/
struct timeval		sum_time(struct timeval a, suseconds_t b);
long long		takeoff_time(struct timeval b);
long long			get_time(struct timeval tv);

int	error(char *str, int err);
int	check_index(int ac, char **av);

#endif