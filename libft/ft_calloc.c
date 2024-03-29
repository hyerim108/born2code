/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:57:30 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/11 17:25:33 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	add;
	void	*result;

	add = count * size;
	result = malloc(add);
	if (!result)
		return (0);
	ft_bzero(result, add);
	return (result);
}
