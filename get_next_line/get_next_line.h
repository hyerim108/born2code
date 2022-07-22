/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:12:55 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/22 19:23:45 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*ft_line(char *buf);
char	*get_next_line(int fd);
char	*ft_backup(char *backup);
size_t	ft_strlen(const char *s);
int		ft_read(int fd, char **backup);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
