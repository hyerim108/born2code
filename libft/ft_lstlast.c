/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:20:48 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/11 14:31:57 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

#include <stdio.h>
int main()
{
	t_list *head = malloc(sizeof(t_list));
	t_list *next = malloc(sizeof(t_list));
	char arr[10] = "10";
	ft_lstnew(arr);
	t_list *con = ft_lstlast(head);
	printf("%s\n",con->content);
}