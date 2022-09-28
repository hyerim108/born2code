/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:49:49 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/28 13:06:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	size;
	int	pivot1;
	int	pivot2;
}	t_stack;

typedef struct s_count
{
	int	ra;
	int	rb;
	int	pb;
	int	pa;
}	t_count;

//main.c
void	print_error(void);

//push_swap.c
void	nogada(t_stack *init);
void	push_swap(int ac, char **av);
void	setting(t_stack *init, int ac, char **av);

//util.c
int		ft_isspace(char c);
int		factor_split(int ac, char **av);
int		get_length(char **str);

//ft_split.c
char	**ft_free(char **str);
size_t	ft_wordcount(char *s, char c);
char	*ft_cpy(char *s, char c);
char	**ft_split(char *s, char c);

//setting_num.c
void	init_stack(t_stack *init, int size);
void	setting_num(t_stack *init, char **av, int ac);
int		check_number(int *arr, int size, int num);
void	swap_stack(t_stack *init);

//ft_atoi.c
int		ft_strlen(char *s);
int		ft_atoi(char *str, int *result);

//util2.c
int		check_a_sort(t_stack *init, int size);
int		check_b_sort(t_stack *init, int size);
void	btoa(t_stack *init, int size);
void	atob(t_stack *init, int size);

//util_size.c
void	size_a(t_stack *init, int size);
void	size_b(t_stack *init, int size);
void	size_3(t_stack *init);

//nogada.c
void	argment_3(t_stack *init);
void	argument_5(t_stack *init);
void	btoa_util(t_stack *init, t_count *cnt, int size);
void	atob_util(t_stack *init, t_count *cnt, int size);

//pivot.c
void	ft_sort(int arr[], int size);
int		*copy_arr(t_stack *init, int size, int flag);
void	get_pivot(t_stack *init, int size, int x);

//reverse_rotate.c
void	rra(t_stack *init, int x);
void	rrb(t_stack *init, int x);
void	rrr(t_stack *init);

//rotate.c
void	ra(t_stack *init, int x);
void	rb(t_stack *init, int x);
void	rr(t_stack *init);

//swap_push.c
void	sa(t_stack *init, int x);
void	sb(t_stack *init, int x);
void	ss(t_stack *init);
void	pa(t_stack *init);
void	pb(t_stack *init);

#endif
