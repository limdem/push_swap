/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:47:04 by dgauvin           #+#    #+#             */
/*   Updated: 2022/04/12 18:47:06 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate_ab(t_stack **root_a, t_stack **root_b)
{
	r_rotate_a(root_a, 1);
	r_rotate_b(root_b, 1);
	write(1, "rrr\n", 4);
}
