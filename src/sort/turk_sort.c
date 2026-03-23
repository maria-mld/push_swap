/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:20:22 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 21:05:28 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	turk_sort(t_stack **a, t_stack **b)
{
	int len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		finish_rotation(a, (*b)->target_node, 'a');
		pa(a, b);
	}
	set_current_index(*a);
	min_on_top(a);
}