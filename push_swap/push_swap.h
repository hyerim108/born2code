/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:27:19 by sujo              #+#    #+#             */
/*   Updated: 2022/09/25 15:40:14 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			size;
	int			pivot1;
	int			pivot2;
}				t_stack;

typedef struct	s_count
{
	int			ra;
	int			rb;
	int			pb;
	int			pa;
}				t_count;
//main.c
void	print_error(void);

//ft_split.c
char	**ft_free(char **str);
size_t	ft_wordcount(char *s, char c);
char	*ft_cpy(char *s, char c);
char	**ft_split(char *s, char c);

//ft_atoi.c
int		ft_strlen(char *s);
int		ft_atoi(char *str, int *result);

//nogada.c
void	argment_sam(t_stack *init);
void	argment_sa(t_stack *init);
void	argument_o(t_stack *init);

void	btoa_util(t_stack *init, t_count *cnt, int size);
void	atob_util(t_stack *init, t_count *cnt, int size);

//pivot.c
void	ft_sort(int arr[], int size);
int		*copy_arr(t_stack *init, int size, int flag);
void	get_pivot(t_stack *init, int size, int x);

//push_swap.c
void	nogada(t_stack *init);
void	setting(t_stack *init, int ac, char **av);
void	push_swap(int argc, char *argv[]);

//setting_num.c
void	initialization_stack(t_stack *init, int size);
int		check_duplicate(int *arr, int size, int num);
void	swap_stack(t_stack *init);
void	setting_num(t_stack *init, char *argv[], int argc);

//util_size.c
void	twothreefour(t_stack *init, int size);
void	onetwothree(t_stack *init, int size);

//util.c
int		get_length(char **str);
int		ft_isspace(char c);
int		factor_split(int ac, char **av);

//util.c
int		check_a_sort(t_stack *init, int size);
int		check_b_sort(t_stack *init, int size);
void	atob(t_stack *init, int size);
void	btoa(t_stack *init, int size);

void	rra(t_stack *init, int x);
void	rrb(t_stack *init, int x);
void	rrr(t_stack *init);

void	ra(t_stack *init, int x);
void	rb(t_stack *init, int x);
void	rr(t_stack *init);

void	sa(t_stack *init, int x);
void	sb(t_stack *init, int x);
void	ss(t_stack *info);
void	pa(t_stack *init);
void	pb(t_stack *init);

#endif
