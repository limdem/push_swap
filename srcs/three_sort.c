/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:56:42 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 18:00:13 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort_pos3(t_stack **root_a)
{
	int	max;
	int	max_pos;

	determine_max(*root_a, &max);
	determine_pos(*root_a, max, &max_pos);
	if (max_pos == 2)
		r_rotate_a(root_a, 0);
	else
	{
		rotate_a(root_a, 0);
		swap_a(root_a, 0);
	}
}

void	three_sort_pos2(t_stack **root_a)
{
	int	max;
	int	max_pos;

	determine_max(*root_a, &max);
	determine_pos(*root_a, max, &max_pos);
	if (max_pos == 1)
		rotate_a(root_a, 0);
	else
		swap_a(root_a, 0);
}

void	three_sort_pos1(t_stack **root_a)
{
	r_rotate_a(root_a, 0);
	swap_a(root_a, 0);
}

void	three_sort(t_push_swap *push_swap)
{
	int	min;
	int	min_pos;

	determine_min(push_swap->root_a, &min);
	determine_pos(push_swap->root_a, min, &min_pos);
	if (min_pos == 1)
		three_sort_pos1(&(push_swap->root_a));
	else if (min_pos == 2)
		three_sort_pos2(&(push_swap->root_a));
	else
		three_sort_pos3(&(push_swap->root_a));
}
