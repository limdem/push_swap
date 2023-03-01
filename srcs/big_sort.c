/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:11:33 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 18:05:57 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_chunk(t_push_swap *push_swap)
{
	while (check_in_chunk(push_swap->root_a, push_swap->dble_chunks))
	{
		list_length(&push_swap->root_a);
		if (push_swap->root_a->stack_len == 1)
		{
			push_number(&push_swap->root_a,
				&push_swap->root_b, push_swap->dble_chunks);
			break ;
		}
		determine_number1(push_swap, &push_swap->push_number.number1);
		determine_number2(push_swap, &push_swap->push_number.number2);
		determine_pos(push_swap->root_a, push_swap->push_number.number1,
			&push_swap->push_number.number1_pos);
		determine_pos(push_swap->root_a, push_swap->push_number.number2,
			&push_swap->push_number.number2_pos);
		determine_push(&push_swap->root_a,
			push_swap->push_number);
		push_number(&push_swap->root_a,
			&push_swap->root_b, push_swap->dble_chunks);
	}
}

void	determine_double_chunk(t_push_swap *push_swap, int count)
{
	if (!count)
	{
		push_swap->index_0 = push_swap->n_chunks / 2;
		push_swap->index_1 = push_swap->index_0 - 1;
	}
	else
	{
		push_swap->index_0++;
		push_swap->index_1--;
	}
	push_swap->dble_chunks[0] = push_swap->chunks[push_swap->index_0];
	push_swap->dble_chunks[1] = push_swap->chunks[push_swap->index_1];
	push_swap->n_chunks -= 2;
}

void	determine_chunk(t_push_swap *push_swap, int chunk_size)
{
	int	i;
	int	j;
	int	save_min;

	i = -1;
	push_swap->n_chunks = push_swap->root_a->stack_len / chunk_size;
	if (push_swap->root_a->stack_len % chunk_size)
		push_swap->n_chunks++;
	push_swap->chunks = malloc(sizeof(t_chunk) * push_swap->n_chunks);
	while (++i < push_swap->n_chunks)
	{
		if (!i)
			determine_min(push_swap->root_a, &push_swap->chunks[i].min);
		else
			push_swap->chunks[i].min = push_swap->chunks[i - 1].max + 1;
		save_min = push_swap->chunks[i].min;
		j = -1;
		while (++j < chunk_size)
			determine_max_chunk(push_swap->root_a, &push_swap->chunks[i].min);
		push_swap->chunks[i].max = push_swap->chunks[i].min;
		push_swap->chunks[i].min = save_min;
	}
}

void	big_sort(t_push_swap *push_swap)
{
	int	init_chunks;
	int	i;

	if (push_swap->root_a->stack_len > 25)
		determine_chunk(push_swap, 25);
	else
		determine_chunk(push_swap, 5);
	init_chunks = push_swap->n_chunks;
	i = -1;
	if (init_chunks % 2)
		init_chunks++;
	if (push_swap->n_chunks > 1)
	{
		while (++i < init_chunks / 2)
		{
			determine_double_chunk(push_swap, i);
			create_chunk(push_swap);
		}
		re_create_stack_a(push_swap);
	}
}
