/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:47:17 by sangyeki          #+#    #+#             */
/*   Updated: 2022/10/05 17:25:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(char *ag, int i, char c)
{
	i--;
	while (i >= 0)
	{
		if (c == ag[i])
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
			int j = 0;
			while (ag[2][j])
			{
				if ((ag[1][i] == ag[2][j]) && !check(ag[1], i, ag[1][i]))
				{
					write(1, &ag[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
}
