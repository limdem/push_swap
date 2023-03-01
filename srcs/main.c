/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:08:04 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/14 14:20:15 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stack_a(t_stack **root, int argc, char *argv[])
{
	t_stack	*curr;
	int		i;

	i = 2;
	*root = malloc(sizeof(t_stack));
	if (!(*root))
		return ;
	(*root)->number = ft_atoi(argv[1]);
	(*root)->prev = NULL;
	(*root)->next = NULL;
	curr = *root;
	while (i < argc)
	{
		curr->next = malloc(sizeof(t_stack));
		if (!curr->next)
			return ;
		curr->next->number = ft_atoi(argv[i]);
		curr->next->prev = curr;
		curr->next->next = NULL;
		curr = curr->next;
		i++;
	}
}

void	initialise_stacks(t_push_swap *push_swap, int argc, char *argv[])
{
	create_stack_a(&push_swap->root_a, argc, argv);
	push_swap->root_b = NULL;
	push_swap->chunks = NULL;
}

void	re_create_stack_a(t_push_swap *push_swap)
{
	int	max;
	int	max_pos;

	while (push_swap->root_b)
	{
		determine_max(push_swap->root_b, &max);
		determine_pos(push_swap->root_b, max, &max_pos);
		list_length(&push_swap->root_b);
		if (max_pos < push_swap->root_b->stack_len / 2)
		{
			while (push_swap->root_b->number != max)
				rotate_b(&push_swap->root_b, 0);
		}
		else
		{
			while (push_swap->root_b->number != max)
				r_rotate_b(&push_swap->root_b, 0);
		}
		push_a(&push_swap->root_a, &push_swap->root_b);
	}
}

void	select_algorithm(t_push_swap *push_swap)
{
	if (is_sorted(push_swap->root_a))
		return ;
	list_length(&push_swap->root_a);
	if (push_swap->root_a->stack_len == 2)
		swap_a(&push_swap->root_a, 0);
	else if (push_swap->root_a->stack_len == 3)
		three_sort(push_swap);
	else if (push_swap->root_a->stack_len <= 5)
		small_sort(push_swap);
	else if (push_swap->root_a->stack_len > 5)
		big_sort(push_swap);
}

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	if (push_swap_parser(argc, argv))
		return (1);
	initialise_stacks(&push_swap, argc, argv);
	select_algorithm(&push_swap);
	free_push_swap(push_swap.root_a, push_swap.chunks);
	return (0);
}
