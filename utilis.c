/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:01:05 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 23:20:55 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	count_args(int argc, char **argv, int *count)
{
	int		i;
	char	**split;
	int		j;

	*count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return ;
		j = 0;
		while (split[j])
		{
			(*count)++;
			j++;
		}
		cleanup(split);
		i++;
	}
}

int	*parse_args(int argc, char **argv, int *count)
{
	int		*values;
	char	**split;
	int		i;
	int		j;
	int		k;

	count_args(argc, argv, count);
	values = malloc(sizeof(int) * (*count));
	if (!values)
		return (NULL);
	i = 0;
	k = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (free(values), NULL);
		j = -1;
		while (split[++j])
			values[k++] = ft_atoi(split[j]);
		cleanup(split);
	}
	return (values);
}

int	calculate_cost(t_stack *a, t_stack *b, int index)
{
	int	pos_b;
	int	cost_a;
	int	cost_b;
	int	cost;

	pos_b = find_position_in_b(b, a->data[index]);
	if (index <= a->size / 2)
		cost_a = index;
	else
		cost_a = -(a->size - index);
	if (pos_b <= b->size / 2)
		cost_b = pos_b;
	else
		cost_b = -(b->size - pos_b);
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs(cost_a) > abs(cost_b))
			cost = abs(cost_a);
		else
			cost = abs(cost_b);
	}
	else
		cost = abs(cost_a) + abs(cost_b);
	return (cost + 1);
}

void	move_to_top(t_stack *stack, int index, char stack_name)
{
	if (!stack || stack->size < 2 || index == 0)
		return ;
	if (index <= stack->size / 2)
	{
		while (index-- > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
	}
	else
	{
		index = stack->size - index;
		while (index-- > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
	}
}
