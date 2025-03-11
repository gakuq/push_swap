/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:03:33 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 22:34:59 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stack	a;
// 	t_stack	b;
// 	int		count;
// 	int		*values;

// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);

// 	values = parse_args(argc, argv, &count);
// 	if (!values)
// 		return (1);

// 	init_stack(&a, values, count);
// 	init_stack(&b, NULL, 0);

// 	sort_stack(&a, &b);
// 	if (argc == 2)
// 		cleanup(argv);

// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		count;
	int		*values;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	values = parse_args(argc, argv, &count);
	validate_args(argc, argv);
	if (!values)
		return (1);
	if (values && has_duplicate(values, count))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	init_stack(&a, values, count);
	init_stack(&b, NULL, 0);
	sort_stack(&a, &b);
	if (a.data)
		free(a.data);
	if (b.data)
		free(b.data);
	free(values);
	return (0);
}
