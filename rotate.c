/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:52:04 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 16:23:57 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotations(t_stack *a, t_stack *b, int a_rot, int b_rot)
{
	while (a_rot > 0 && b_rot-- > 0)
	{
		rr(a, b);
		a_rot--;
	}
	while (a_rot++ < 0 && b_rot++ < 0)
		rrr(a, b);
	while (a_rot-- > 0)
		ra(a);
	while (a_rot++ < 0)
		rra(a);
	while (b_rot-- > 0)
		rb(b);
	while (b_rot++ < 0)
		rrb(b);
}

void	rotate(t_stack	*a)
{
	int	tmp;
	int	i;

	if (!a || a->size < 2)
		return ;
	tmp = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = tmp;
}

void	ra(t_stack	*a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack	*b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack	*a, t_stack	*b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
