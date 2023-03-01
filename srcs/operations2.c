/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:43:57 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 18:52:43 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **root_a, int ab)
{
	t_stack	*curr;
	t_stack	*save_node;

	if (!(*root_a))
		return ;
	list_length(root_a);
	if ((*root_a)->stack_len < 2)
		return ;
	curr = *root_a;
	save_node = *root_a;
	*root_a = (*root_a)->next;
	(*root_a)->prev = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = save_node;
	curr->next->prev = curr;
	curr->next->next = NULL;
	if (!ab)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **root_b, int ab)
{
	t_stack	*curr;
	t_stack	*save_node;

	if (!(*root_b))
		return ;
	list_length(root_b);
	if ((*root_b)->stack_len < 2)
		return ;
	curr = *root_b;
	save_node = *root_b;
	*root_b = (*root_b)->next;
	(*root_b)->prev = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = save_node;
	curr->next->prev = curr;
	curr->next->next = NULL;
	if (!ab)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **root_a, t_stack **root_b)
{
	rotate_a(root_a, 1);
	rotate_b(root_b, 1);
	write(1, "rr\n", 3);
}

void	r_rotate_a(t_stack **root_a, int ab)
{
	t_stack	*tmp_node;
	t_stack	*save_node;

	list_length(root_a);
	if (!(*root_a) || (*root_a)->stack_len < 2)
		return ;
	tmp_node = *root_a;
	while ((*root_a)->next)
		*root_a = (*root_a)->next;
	save_node = (*root_a)->prev;
	(*root_a)->next = tmp_node;
	(*root_a)->prev = NULL;
	save_node->next = NULL;
	(*root_a)->next->prev = *root_a;
	if (!ab)
		write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **root_b, int ab)
{
	t_stack	*tmp_node;
	t_stack	*save_node;

	list_length(root_b);
	if (!(*root_b) || (*root_b)->stack_len < 2)
		return ;
	tmp_node = *root_b;
	while ((*root_b)->next)
		*root_b = (*root_b)->next;
	save_node = (*root_b)->prev;
	(*root_b)->next = tmp_node;
	(*root_b)->prev = NULL;
	save_node->next = NULL;
	(*root_b)->next->prev = *root_b;
	if (!ab)
		write(1, "rrb\n", 4);
}
