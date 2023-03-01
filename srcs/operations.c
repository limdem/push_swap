/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:20:57 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 18:46:01 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **root_a, int ab)
{
	t_stack	*save_node;

	list_length(root_a);
	if ((*root_a)->stack_len < 2)
		return ;
	save_node = *root_a;
	*root_a = (*root_a)->next;
	(*root_a)->prev = NULL;
	save_node->next = (*root_a)->next;
	(*root_a)->next = save_node;
	if (save_node->next)
		save_node->next->prev = save_node;
	(*root_a)->next->prev = *root_a;
	if (!ab)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **root_b, int ab)
{
	t_stack	*save_node;

	list_length(root_b);
	if ((*root_b)->stack_len < 2)
		return ;
	save_node = *root_b;
	*root_b = (*root_b)->next;
	(*root_b)->prev = NULL;
	save_node->next = (*root_b)->next;
	(*root_b)->next = save_node;
	if (save_node->next)
		save_node->next->prev = save_node;
	(*root_b)->next->prev = *root_b;
	if (!ab)
		write(1, "sb\n", 3);
}

void	swap_ab(t_stack **root)
{
	swap_a(root, 1);
	swap_b(root, 1);
	write(1, "ss\n", 3);
}

void	push_a(t_stack **root_a, t_stack **root_b)
{
	t_stack	*save_root_a;

	if (!(*root_b))
		return ;
	save_root_a = *root_a;
	*root_a = *root_b;
	list_length(root_b);
	if (!((*root_b)->stack_len > 1))
		*root_b = NULL;
	else
	{
		*root_b = (*root_b)->next;
		(*root_b)->prev = NULL;
	}
	if (!save_root_a)
	{
		(*root_a)->next = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	(*root_a)->next = save_root_a;
	save_root_a->prev = *root_a;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **root_a, t_stack **root_b)
{
	t_stack	*save_root_b;

	if (!(*root_a))
		return ;
	save_root_b = *root_b;
	*root_b = *root_a;
	list_length(root_a);
	if (!((*root_a)->stack_len > 1))
		*root_a = NULL;
	else
	{
		*root_a = (*root_a)->next;
		(*root_a)->prev = NULL;
	}
	if (!save_root_b)
	{
		(*root_b)->next = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	(*root_b)->next = save_root_b;
	save_root_b->prev = *root_b;
	write(1, "pb\n", 3);
}
