/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:51 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/12 19:35:01 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_content
{
	struct s_content	*pre;
	int					content;
	struct s_content	*next;
}	t_content;

typedef struct s_stack
{
	struct s_content	*top_a;
	struct s_content	*bottom_a;
	struct s_content	*top_b;
	struct s_content	bottom_b;
}	t_stack;

int factor_split(int ac, char **av);
int	ft_strlen(char *s);
char	**ft_split(char *s, char c);
int	get_length(char **str);
int	ft_isspace(int c);
int *number_check(int ac, char **av, int size);
void    setting_num(int *num_array, int *index, char **split_data);
int	ft_atoi(char *str);
void    print_error();

#endif