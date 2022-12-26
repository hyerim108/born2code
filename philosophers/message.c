/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:16 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/26 18:24:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_philo *p, int a, int b)
{
	int		ret;

	pthread_mutex_lock(&p->all->write_m);
	ret = takeoff_time(p->all->start);
	printf("%s%d %d ", off, ret / 1000, p->n);
	if (a == TYPE_EAT)
		printf("%sis eating\n", CYAN);
	if (a == TYPE_SLEEP)
		printf("%sis sleeping\n", PEO);
	if (a == TYPE_FORK)
		printf("%shas taken a fork\n", RED);
	if (a == TYPE_THINK)
		printf("%sis thinking\n", YEL);
	if (a == TYPE_DIED)
		printf("%shas died\n", RED);
	if (a == TYPE_OVER)
		printf("%smust eat count reached\n", RED);
	if (b)
		pthread_mutex_unlock(&p->all->write_m);
}