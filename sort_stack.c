/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:25:27 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/04 14:11:15 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->size <= 1)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->size == 2)
			sa(a);
		else if (a->size == 3)
			sort_three(a);
		else
			turk_sort(a, b);
	}
}
