/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:46:04 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/06 18:28:12 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_map(char *av, t_param *p)
{
	int	fd;

	if (ft_strcmp(".cub", &av[ft_strlen(&av[1]) - 3]) != 0)
		error("Not *.cub file");
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		error("file open Error");
}
