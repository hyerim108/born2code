/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:16 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/29 18:33:07 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_philo *p, int a, int b)
{
	int		ret;

	pthread_mutex_lock(&p->all->write_t);
	printf("%s%lld %d ", WHI, get_time() - p->time, p->n);
	if (a == EAT)
		printf("%sis eating\n", CYAN);
	if (a == SLEEP)
		printf("%sis sleeping\n", PEO);
	if (a == FORK)
		printf("%shas taken a fork\n", RED);
	if (a == THINK)
		printf("%sis thinking\n", YEL);
	if (a == DIED)
		printf("%shas died\n", RED);
	if (a == OVER)
		printf("%smust eat count reached\n", RED);
	if (b)
		pthread_mutex_unlock(&p->all->write_t);
}