/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:50:59 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 22:18:51 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*alloc_n_copy(int *src, int size, int offset)
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < size - offset)
	{
		new_arr[i] = src[i + offset];
		i++;
	}
	return (new_arr);
}

static void	remove_top_element(t_stack *src)
{
	int	*new_arr;

	new_arr = alloc_n_copy(src->data, src->size, 1);
	if (!new_arr && src->size > 0)
	{
		return ;
	}
	free(src->data);
	if (src->size > 0)
		src->data = new_arr;
	else
		src->data = NULL;
	src->size--;
}

static void	push_stack(t_stack *dest, t_stack *src)
{
	int	*new_arr;
	int	i;

	if (!src || src->size < 1)
		return ;
	new_arr = malloc(sizeof(int) * (dest->size + 1));
	if (!new_arr)
		return ;
	new_arr[0] = src->data[0];
	i = 0;
	while (i < dest->size)
	{
		new_arr[i + 1] = dest->data[i];
		i++;
	}
	free(dest->data);
	dest->data = new_arr;
	dest->size++;
	remove_top_element(src);
}

void	pa(t_stack	*a, t_stack	*b)
{
	push_stack(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack	*a, t_stack	*b)
{
	push_stack(b, a);
	ft_printf("pb\n");
}
