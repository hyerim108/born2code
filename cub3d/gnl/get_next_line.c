/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:32:54 by sangyeki          #+#    #+#             */
/*   Updated: 2022/04/11 14:19:00 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*target;
	int			ret;

	target = 0;
	ret = 1;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	if (ft_seek(buf, '\n') != -1)
	{
		ft_cut_line(buf, '\n');
		target = ft_strjoin(target, buf);
		if (target[0] == 0)
			target = ft_free(target);
	}
	while (ret > 0 && ft_seek(buf, '\n') == -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			return (target);
		buf[ret] = 0;
		target = ft_strjoin(target, buf);
	}
	return (target);
}
