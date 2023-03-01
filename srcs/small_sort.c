/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:03:36 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 17:09:20 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_push(t_stack **root_a, t_stack **root_b, int nb, int nb_pos)
{
	list_length(root_a);
	if (nb_pos < (*root_a)->stack_len / 2)
	{
		while ((*root_a)->number != nb)
			rotate_a(root_a, 0);
	}
	else
	{
		while ((*root_a)->number != nb)
			r_rotate_a(root_a, 0);
	}
	push_b(root_a, root_b);
}

void	push_max_min(t_stack **root_a, t_stack **root_b, int max, int min)
{
	int	max_pos;
	int	min_pos;

	determine_pos(*root_a, min, &min_pos);
	if ((*root_a)->stack_len == 4)
		quick_push(root_a, root_b, min, min_pos);
	else
	{
		determine_pos(*root_a, max, &max_pos);
		if (max_pos < (*root_a)->stack_len - min_pos)
		{
			quick_push(root_a, root_b, max, max_pos);
			determine_pos(*root_a, min, &min_pos);
			quick_push(root_a, root_b, min, min_pos);
		}
		else
		{
			quick_push(root_a, root_b, min, min_pos);
			determine_pos(*root_a, max, &max_pos);
			quick_push(root_a, root_b, max, max_pos);
		}
	}
}

void	small_sort(t_push_swap *push_swap)
{
	int	max;
	int	min;
	int	len;

	len = push_swap->root_a->stack_len;
	determine_min(push_swap->root_a, &min);
	if (push_swap->root_a->stack_len == 5)
		determine_max(push_swap->root_a, &max);
	push_max_min(&push_swap->root_a, &push_swap->root_b, max, min);
	if (!is_sorted(push_swap->root_a))
		three_sort(push_swap);
	if (!(is_sorted(push_swap->root_b)))
		swap_b(&push_swap->root_b, 0);
	push_a(&push_swap->root_a, &push_swap->root_b);
	if (len == 5)
	{
		push_a(&push_swap->root_a, &push_swap->root_b);
		rotate_a(&push_swap->root_a, 0);
	}
}
