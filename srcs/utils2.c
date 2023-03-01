/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:13:21 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/14 14:19:43 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"  

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (sign * result);
}

void	free_push_swap(t_stack *root_a, t_chunk *chunks)
{
	t_stack	*curr;
	t_stack	*save_curr;

	curr = root_a;
	while (curr)
	{
		save_curr = curr;
		curr = curr->next;
		free(save_curr);
	}
	if (chunks)
		free(chunks);
}

void	list_length(t_stack **root)
{
	t_stack	*curr;
	int		count;

	count = 0;
	curr = *root;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	(*root)->stack_len = count;
}

int	is_sorted(t_stack *root_a)
{
	int	counter;

	counter = 0;
	while (root_a->next)
	{
		root_a = root_a->next;
		if (root_a->number < root_a->prev->number)
			return (0);
		counter++;
	}
	return (1);
}

void	determine_max_chunk(t_stack *root, int *min)
{
	t_stack	*curr;
	int		prev_min;

	if (!root)
		return ;
	curr = root;
	prev_min = *min;
	while (curr)
	{
		if (curr->number > *min)
		{
			*min = curr->number;
			break ;
		}
		curr = curr->next;
	}
	while (curr)
	{
		if (curr->number < *min && curr->number > prev_min)
			*min = curr->number;
		curr = curr->next;
	}
}
