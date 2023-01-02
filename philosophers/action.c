/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:08 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/02 15:15:25 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_fork(t_philo *p)
{
	pthread_mutex_lock(&p->all->fork[p->lfork]);
	message(p, FORK, 1);
	pthread_mutex_lock(&p->all->fork[p->rfork]);
	message(p, FORK, 1);
}

void	eat(t_philo *p)
{
	p->is_eating = 1;
	message(p, EAT, 1);
	p->eat_count++;
	p->time = get_time();
	ft_sleep(p->all->time_to_eat);
	p->is_eating = 0;
}

void	put_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->all->fork[p->lfork]);
	pthread_mutex_unlock(&p->all->fork[p->rfork]);
	message(p, SLEEP, 1);
	ft_sleep(p->all->time_to_eat);
	message(p, THINK, 1);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
