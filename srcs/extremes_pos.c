/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremes_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:43:09 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 16:52:37 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	determine_min(t_stack *root, int *min)
{
	t_stack	*curr;

	if (!root)
		return ;
	curr = root;
	*min = curr->number;
	while (curr)
	{
		if (!curr->next)
			break ;
		if (curr->next->number < *min)
			*min = curr->next->number;
		curr = curr->next;
	}
}

void	determine_max(t_stack *root, int *max)
{
	t_stack	*curr;

	if (!root)
		return ;
	curr = root;
	*max = curr->number;
	while (curr)
	{
		if (!curr->next)
			break ;
		if (curr->next->number > *max)
			*max = curr->next->number;
		curr = curr->next;
	}
}

void	determine_pos(t_stack *root, int number, int *pos)
{
	t_stack	*curr;

	curr = root;
	*pos = 1;
	while (curr->number != number && curr)
	{
		curr = curr->next;
		(*pos)++;
	}
}
