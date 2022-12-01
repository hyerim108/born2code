/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:41:58 by sangyeki          #+#    #+#             */
/*   Updated: 2022/10/05 17:48:15 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int check(char *ag, int i, char c)
{
	i--;
	while (i >= 0)
	{
		if (ag[i] == c)
			return (1);
		i--;
	}
	return (0);
}

int main(int ac, char **ag)
{
	if (ac == 3)
	{
		int i = 0;
		while (ag[1][i])
		{
			if (!check(ag[1], i, ag[1][i]))
				write(1, &ag[1][i], 1);
			i++;
		}
		int j = 0;
		while (ag[2][j])
		{
			if (!(check(ag[1], i, ag[2][j])) && !(check(ag[2], j, ag[2][j])))
				write(1, &ag[2][j], 1);
			j++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
