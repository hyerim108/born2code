/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:45:41 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 14:09:16 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int	ft_strlen_g(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int	ft_strlen_buf(char *str)
{
	int	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] && str[len] == '\n')
		len++;
	return (len);
}

void	ft_cut_line(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	while (j < BUFFER_SIZE - i)
	{
		str[j] = str[j + i];
		j++;
	}
	str[j] = 0;
}

char	*ft_strjoin_g(char *str, char *str2)
{
	int		i_len;
	int		j_len;
	char	*target;

	i_len = ft_strlen_g(str);
	j_len = ft_strlen_buf(str2);
	target = malloc(sizeof(char) * (i_len + j_len + 1));
	if (target)
	{
		i_len = -1;
		j_len = -1;
		while (str && str[++i_len])
			target[i_len] = str[i_len];
		if (i_len == -1)
			i_len = 0;
		while (str2 && str2[++j_len] && str2[j_len] != '\n')
			target[i_len + j_len] = str2[j_len];
		target[i_len + j_len] = str2[j_len];
		if ((str2 && str2[j_len] && str2[j_len] == '\n') || j_len == -1)
			j_len++;
		target[i_len + j_len] = 0;
	}
	free(str);
	str = NULL;
	return (target);
}

int	ft_seek(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
