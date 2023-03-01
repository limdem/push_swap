/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:55:09 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/14 13:35:43 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	determine_push(t_stack **root_a, t_push_number push_number)
{
	list_length(root_a);
	if (push_number.number1_pos
		<= ((*root_a)->stack_len - push_number.number2_pos + 1))
	{
		while ((*root_a)->number != push_number.number1)
			rotate_a(root_a, 0);
	}
	else
	{
		while ((*root_a)->number != push_number.number2)
			r_rotate_a(root_a, 0);
	}
}

void	determine_number2(t_push_swap *push_swap, int *number)
{
	t_stack	*curr;

	curr = push_swap->root_a;
	while (curr->next)
		curr = curr->next;
	while (curr)
	{
		if ((curr->number >= push_swap->dble_chunks[0].min
				&& curr->number <= push_swap->dble_chunks[0].max)
			|| (curr->number >= push_swap->dble_chunks[1].min
				&& curr->number <= push_swap->dble_chunks[1].max))
		{
			*number = curr->number;
			break ;
		}
		curr = curr->prev;
	}
}

void	determine_number1(t_push_swap *push_swap, int *number)
{
	t_stack	*curr;

	curr = push_swap->root_a;
	while (curr->next)
	{
		if ((curr->number >= push_swap->dble_chunks[0].min
				&& curr->number <= push_swap->dble_chunks[0].max)
			|| (curr->number >= push_swap->dble_chunks[1].min
				&& curr->number <= push_swap->dble_chunks[1].max))
		{
			*number = curr->number;
			break ;
		}
		curr = curr->next;
	}
}

void	push_number(t_stack **root_a, t_stack **root_b, t_chunk dble_chunks[2])
{
	if (!((*root_a)->number >= dble_chunks[0].min
			&& (*root_a)->number <= dble_chunks[0].max))
	{
		push_b(root_a, root_b);
		if (!(*root_a))
			return ;
		if (!(((*root_a)->number >= dble_chunks[0].min
					&& (*root_a)->number <= dble_chunks[0].max)
				|| ((*root_a)->number >= dble_chunks[1].min
					&& (*root_a)->number <= dble_chunks[1].max)))
			rotate_ab(root_a, root_b);
		else
			rotate_b(root_b, 0);
	}
	else
	{
		if (!(*root_a))
			return ;
		push_b(root_a, root_b);
	}
}

int	check_in_chunk(t_stack *root, t_chunk dble_chunk[2])
{
	t_stack	*curr;

	if (!root)
		return (0);
	curr = root;
	while (curr)
	{
		if ((curr->number >= dble_chunk[0].min
				&& curr->number <= dble_chunk[0].max)
			|| (curr->number >= dble_chunk[1].min
				&& curr->number <= dble_chunk[1].max))
			return (1);
		curr = curr->next;
	}
	return (0);
}
