/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:53:07 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 17:03:11 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;
	int	number1;
	int	number2;

	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
		{
			number1 = ft_atoi(argv[i]);
			number2 = ft_atoi(argv[j]);
			if (number1 == number2)
			{
				write(1, "Error\n", 6);
				return (1);
			}
		}
	}
	return (0);
}

int	check_is_number(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (!((argv[i][j] == '+' || argv[i][j] == '-')
					&& j == 0 && ft_strlen(argv[i]) > 1))
				{
					write(1, "Error\n", 6);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	check_is_integer(int argc, char *argv[])
{
	long	number;
	int		i;

	i = 0;
	while (++i < argc)
	{
		number = ft_atol(argv[i]);
		if (!(number >= INT_MIN && number <= INT_MAX))
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

int	push_swap_parser(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (check_is_number(argc, argv))
		return (1);
	if (check_is_integer(argc, argv))
		return (1);
	if (check_duplicates(argc, argv))
		return (1);
	return (0);
}
