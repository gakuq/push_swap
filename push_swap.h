/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:04:58 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 16:42:19 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

//Errors Handler
int		has_duplicate(int *arr, int size);
void	validate_args(int argc, char **argv);

//Stack initiation
void	init_stack(t_stack *stack, int *values, int count);

//Stack utilis
int		*parse_args(int argc, char **argv, int *count);
void	cleanup(char **argv);
void	move_to_top(t_stack *stack, int index, char stack_name);
int		is_sorted(t_stack *a);
int		find_min_index(t_stack *stack);
int		calculate_cost(t_stack *a, t_stack *b, int index);
int		find_position_in_b(t_stack *b, int value);
int		find_min_index(t_stack *stack);
int		find_insert_position(t_stack *a, int value);
void	execute_rotations(t_stack *a, t_stack *b, int a_rot, int b_rot);
//Commands
void	pa(t_stack	*a, t_stack	*b);
void	pb(t_stack	*a, t_stack	*b);
void	swap(t_stack *a);
void	sa(t_stack	*a);
void	sb(t_stack	*b);
void	ss(t_stack	*a, t_stack	*b);
void	rotate(t_stack	*a);
void	ra(t_stack	*a);
void	rb(t_stack	*b);
void	rr(t_stack	*a, t_stack	*b);
void	revrotate(t_stack *a);
void	rra(t_stack	*a);
void	rrb(t_stack	*b);
void	rrr(t_stack	*a, t_stack	*b);
//Algorithms
void	sort_three(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);

#endif