/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:59:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/07/20 14:51:31 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_putnbr(int nbr);
int					ft_plusnbr(int nbr);
int					ft_base(char c, unsigned int nbr);
int					ft_printf(const char *format, ...);
unsigned long long	ft_memory(unsigned long long *nbr);
int					ft_putsymbol(const char *format, int i, va_list ap);

#endif