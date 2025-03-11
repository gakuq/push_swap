/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:39:03 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 22:19:47 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_in_b(t_stack *b, int value)
{
	int	i;
	int	max_index;
	int	min_index;

	i = 0;
	max_index = 0;
	min_index = 0;
	if (!b || b->size == 0)
		return (0);
	while (++i < b->size)
	{
		if (b->data[i] > b->data[max_index])
			max_index = i;
		else if (b->data[i] < b->data[min_index])
			min_index = i;
	}
	if (value > b->data[max_index] || value < b->data[min_index])
		return (max_index);
	i = -1;
	while (++i < b->size - 1)
		if (b->data[i] >= value && value > b->data[i + 1])
			return (i + 1);
	return (0);
}

int	find_min_index(t_stack *stack)
{
	int	min_index;
	int	i;

	if (!stack || stack->size == 0)
		return (-1);
	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < stack->data[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	find_insert_position(t_stack *a, int value)
{
	int	i;
	int	next;

	if (!a || a->size == 0)
		return (0);
	i = 0;
	while (i < a->size)
	{
		next = (i + 1) % a->size;
		if (a->data[i] < value && value < a->data[next])
			return (next);
		i++;
	}
	return (find_min_index(a));
}
