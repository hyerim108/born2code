/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:34:35 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/30 11:04:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

/* utils */
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* utils2 */
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strd_up(const char *s1);
size_t	ft_strcpy(char *dst, const char *src);

#endif
