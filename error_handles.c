/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:02:46 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/11 22:42:06 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_int(char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

void	check_error(char **args, int error)
{
	if (error)
	{
		write(2, "Error\n", 6);
		if (args)
			cleanup(args);
		exit(1);
	}
}

void	validate_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			check_error(NULL, 1);
		j = 0;
		while (args[j])
		{
			check_error(args, !is_valid_int(args[j]));
			j++;
		}
		cleanup(args);
		i++;
	}
}

// void	validate_args(int argc, char **argv)
// {
// 	int		i;
// 	char	**args;

// 	args = NULL;
// 	if (argc == 2)
// 	{
// 		args = ft_split(argv[1], ' ');
// 		i = -1;
// 		while (args[++i])
// 			check_error(args, !is_valid_int(args[i]));
// 		cleanup(args);
// 		return ;
// 	}
// 	i = 0;
// 	while (++i < argc)
// 		check_error(NULL, !is_valid_int(argv[i]));
// }
