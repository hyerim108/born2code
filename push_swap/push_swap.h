/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:51 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/22 15:00:49 by hyerimki         ###   ########.fr       */
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
	int	pivot2;
}	t_stack;

typedef struct s_append
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_append;

void	print_error(int num);

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
int		check_a(t_stack *init, int size);
int		check_b(t_stack *init, int size);
void	clean_b(t_stack *init, int size, t_append *c);
void	clean_a(t_stack *init, int size, t_append *c);

int		ft_strlen(char *s);
int		get_length(char **str);
int		ft_isspace(char c);
int		ft_atoi(char *str, int *result);

void	sort_array(int *arr, int size);
void    send_sort(t_stack *init, int size, t_append *count);
void    send_a(t_stack *init, int size);

void    argment_3(t_stack *init);
void	argment_4(t_stack *init);
void	argment_5(t_stack *init);
void	swap_stack(t_stack *init);
void	nogada(t_stack *init);

void	check_noga(t_stack *init, int size);

void	pb(t_stack *init);
void	pa(t_stack *init);
void	ra(t_stack *init, int trues);
void	rb(t_stack *init, int trues);
void	rr(t_stack *init);

void	sa(t_stack *init, int trues);
void	sb(t_stack *init, int trues);
void	ss(t_stack *init);

void	rra(t_stack *init, int trues);
void	rrb(t_stack *init, int trues);
void	rrr(t_stack *init);

#endif
