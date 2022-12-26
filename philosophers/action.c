/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:08 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/26 18:09:32 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_fork(t_philo *p)
{
	pthread_mutex_lock(&p->all->fork_m[p->lfork]);
	message(p, TYPE_FORK, 1);
	pthread_mutex_lock(&p->all->fork_m[p->rfork]);
	message(p, TYPE_FORK, 1);
}

void	eat(t_philo *p)
{
	p->is_eating = 1;
	message(p, TYPE_EAT, 1);
	gettimeofday(&p->last_eat, NULL);
	p->max = sum_time(p->last_eat, p->all->time_to_die * 1000);
	p->eat_count++;
	usleep(p->all->time_to_eat * 1000);
	p->is_eating = 0;
}

void	put_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->all->fork_m[p->lfork]);
	pthread_mutex_unlock(&p->all->fork_m[p->rfork]);
	message(p, TYPE_SLEEP, 1);
	usleep(p->all->time_to_sleep * 1000);
	message(p, TYPE_THINK, 1);
}