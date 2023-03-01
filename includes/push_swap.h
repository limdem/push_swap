/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:25:21 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/14 14:38:07 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>
# include <string.h>

typedef struct s_stack
{
	int				stack_len;
	int				number;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	min_pos;
	int	max_pos;
	int	len;
}	t_chunk;

typedef struct s_push_number
{
	int	number1;
	int	number2;
	int	number1_pos;
	int	number2_pos;
}	t_push_number;

typedef struct s_push_swap
{
	t_stack			*root_a;
	t_stack			*root_b;
	t_chunk			*chunks;
	t_push_number	push_number;
	t_chunk			dble_chunks[2];
	int				n_chunks;
	int				index_0;
	int				index_1;
}	t_push_swap;

size_t	ft_strlen(const char *s);

long	ft_atol(const char *nptr);

int		ft_isdigit(int c);
int		push_swap_parser(int argc, char *argv[]);
int		ft_atoi(const char *nptr);
int		is_sorted(t_stack *root_a);
int		is_sorted(t_stack *root_a);
int		check_in_chunk(t_stack *root, t_chunk dble_chunk[2]);

void	list_length(t_stack **root);
void	small_sort(t_push_swap *push_swap);
void	re_create_stack_a(t_push_swap *push_swap);
void	determine_max_chunk(t_stack *root, int *min);
void	determine_push(t_stack **root_a, t_push_number push_number);
void	determine_number2(t_push_swap *push_swap, int *number);
void	determine_number1(t_push_swap *push_swap, int *number);
void	push_number(t_stack **root_a, t_stack **root_b, t_chunk dble_chunks[2]);
void	free_push_swap(t_stack *root_a, t_chunk *chunks);
void	big_sort(t_push_swap *push_swap);
void	create_stack_a(t_stack **root, int argc, char *argv[]);
void	determine_pos(t_stack *root, int number, int *pos);
void	three_sort_pos3(t_stack **root_a);
void	three_sort_pos2(t_stack **root_a);
void	three_sort_pos1(t_stack **root_a);
void	three_sort(t_push_swap *push_swap);
void	determine_max(t_stack *root, int *max);
void	determine_min(t_stack *root, int *min);
void	three_numbers(t_push_swap *push_swap);
void	list_length(t_stack **root);
void	swap_a(t_stack **root_a, int ab);
void	swap_b(t_stack **root_b, int ab);
void	swap_ab(t_stack **root);
void	push_a(t_stack **root_a, t_stack **root_b);
void	push_b(t_stack **root_a, t_stack **root_b);
void	rotate_a(t_stack **root_a, int ab);
void	rotate_b(t_stack **root_b, int ab);
void	rotate_ab(t_stack **root_a, t_stack **root_b);
void	r_rotate_a(t_stack **root_a, int ab);
void	r_rotate_b(t_stack **root_b, int ab);
void	r_rotate_ab(t_stack **root_a, t_stack **root_b);
#endif
