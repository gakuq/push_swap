/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:43:50 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 21:09:00 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheapest_to_b(t_stack *a, t_stack *b)
{
	int	min_cost;
	int	best_index;
	int	cost;
	int	i;

	min_cost = INT_MAX;
	best_index = 0;
	i = 0;
	while (i < a->size)
	{
		cost = calculate_cost(a, b, i);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_index = i;
		}
		i++;
	}
	move_to_top(a, best_index, 'a');
	move_to_top(b, find_position_in_b(b, a->data[0]), 'b');
	pb(a, b);
}

void	push_all_but_three(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		push_cheapest_to_b(a, b);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		move_to_top(a, find_insert_position(a, b->data[0]), 'a');
		pa(a, b);
	}
}

void	arrange_final_stack(t_stack *a)
{
	int	min_index;

	min_index = find_min_index(a);
	move_to_top(a, min_index, 'a');
}

void	turk_sort(t_stack *a, t_stack *b)
{
	push_all_but_three(a, b);
	if (a->size < 3 && !is_sorted(a))
		sa(a);
	else
		sort_three(a);
	push_back_to_a(a, b);
	arrange_final_stack(a);
}
