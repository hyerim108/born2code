/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:09 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/01 16:03:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    mutex_setting(t_pthread *pthread, int x)
{
    if (x)
    {
       pthread_mutex_lock(&pthread->all->forks[(pthread->i) \
        % pthread->all->n_philo]);
        out(pthread, "taken a fork", 1);
        pthread_mutex_lock(&pthread->all->forks[(pthread->i + 1) \
            % pthread->all->n_philo]);
        out(pthread, "taken a fork", 1);
    }
    else
    {
        pthread_mutex_unlock(&pthread->all->forks[(pthread->i) \
            % pthread->all->n_philo]);
            pthread_mutex_unlock(&pthread->all->forks[(pthread->i + 1) \
            % pthread->all->n_philo]);
    }
}

void    *func(void  *param)
{
    t_pthread   *pthread;
    
    pthread = param;
    if(pthread->i % 2)
        ft_usleep(pthread->all->time_to_eat / 2);
    while (1)
    {
        mutex_setting(pthread, 1);
        out(pthread, "is eating", 1);
        ft_usleep(pthread->all->time_to_eat);
        mutex_setting(pthread, 0);
        pthread->time = get_time();
        out(pthread, "is sleeping", 1);
        ft_usleep(pthread->all->time_to_sleep);
        out(pthread, "is thinking", 1);
    }
}
void    ft_thread(t_philo *philo)
{
    int i;

    i = -1;
    pthread_mutex_init(&philo->mutex, NULL); //mutex creat
    while(++i < philo->n_philo)
        pthread_create(&philo->philos[i].thread, NULL, func, &philo->philos[i]);
    i = -1;
    while(++i < philo->n_philo)
        pthread_detach(philo->philos[i].thread);
}