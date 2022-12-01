/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:21:50 by sangyeki          #+#    #+#             */
/*   Updated: 2022/10/06 22:06:58 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(char **line)
{
    int i = 0;
    int s = 1;
    int r = 0;
    char c;
    char *tmp;
    
    if (!(*line = malloc(s)))
        return (-1);
    (*line)[0] = 0;

    while ((r = read(0, &c, 1)) && c != '\n' && s++)
    {
        if (!(tmp = malloc(s)))
        {
            free(*line);
            return (-1);
        }
        i = -1;
        while (++i < s - 2)
            tmp[i] = (*line)[i];
        tmp[i] = c;
        tmp[i + 1] = 0;
        free(*line);
        (*line) = tmp;
    }
    return (r);
}
