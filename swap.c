/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:46:42 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/06 15:56:32 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
}

void	sa(t_stack	*a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack	*b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack	*a, t_stack	*b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
