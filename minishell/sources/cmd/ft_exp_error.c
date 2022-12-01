/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:44:38 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/16 12:44:40 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exp_error(int q[3], int *r_n)
{
	if (q[2] >= 2 && *r_n == -2)
	{
		printf("bash: export: not valid in this context\n");
		return (2);
	}
	else
	{
		q[2] = 1;
		return (1);
	}
}
