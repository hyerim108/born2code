/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:51 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/18 17:21:38 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
	int	size;
	int	pivot1;
	int pivot2;
}	t_stack;

typedef struct s_append
{
	int	ra;
	int rb;
	int pa;
	int pb;
}	t_append;

int		print_error(int num);

void	checking(t_stack *init, int ac, char **av, int size);
void	initialization_stack(t_stack *init, int size);
void	setting(t_stack *init, int ac, char **av);
void	push_swap(int ac, char **av);

char	**ft_free(char **str);
size_t	ft_wordcount(char *s, char c);
char	*ft_cpy(char *s, char c);
char	**ft_split(char *s, char c);

int		factor_split(int ac, char **av);
void	setting_pivot(t_stack *init, int size, int f);
int		*c_paste(t_stack *init, int size, int f);
int		check_sort(t_stack *init, int size);
void	b_send(t_stack *init, int size, t_append *c);

int		ft_strlen(char *s);
int		get_length(char **str);
int		ft_isspace(char c);
int		ft_atoi(const char *str);
int		ft_atoi2(char *str, int *result);

#endif
