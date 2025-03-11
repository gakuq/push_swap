/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:20:26 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 21:03:42 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int *values, int count)
{
	int	i;

	stack->data = NULL;
	i = 0;
	if (count > 0)
	{
		stack->data = malloc(sizeof(int) * count);
		if (!stack->data)
			return ;
	}
	i = 0;
	while (count > i)
	{
		stack->data[i] = values[i];
		i++;
	}
	stack->size = count;
}
