/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:03:26 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/06 15:56:05 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack	*a)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
}

void	rra(t_stack	*a)
{
	revrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack	*b)
{
	revrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack	*a, t_stack	*b)
{
	revrotate(a);
	revrotate(b);
	ft_printf("rrr\n");
}
