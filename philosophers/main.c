/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:43:24 by hyerimki          #+#    #+#             */
/*   Updated: 2022/12/16 18:34:28 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str, int err)
{
	printf("%s", str);
	return (err);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac != 5 && ac != 6) || !check_index(ac, av))
		return (error("argument Error", 2));
	if (!setting_init(&philo, av))
		return (error("allocation Error", 2));
	ft_thread(&philo);
	ft_die(&philo);
	ft_free(&philo);
	return (0);
}
