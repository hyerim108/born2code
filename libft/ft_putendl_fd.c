/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:12:59 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/07 13:14:41 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (fd < 0)
        return ;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
    write(fd, "\n", 1);
}