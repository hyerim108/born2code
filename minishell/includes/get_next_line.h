/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:37:09 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/10 14:11:04 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen_g(char *str);
int		ft_strlen_buf(char *str);
char	*ft_strjoin_g(char *str, char *str2);
void	ft_cut_line(char *str, char c);
int		ft_seek(char *str, char c);
char	*ft_free(char *str);

#endif
