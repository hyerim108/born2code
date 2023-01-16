/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:46:04 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/16 12:42:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	build_map(char *av, t_param *p)
{
	if (ft_strcmp(".cub", &av[ft_strlen(&av[1]) - 3]) != 0)
		error("Not *.cub file");
	initialization_param(&p->map, av);
	initialization_image(&p->img);
	initialization_move(&p->move);
	map_parshing(av, p);
}
