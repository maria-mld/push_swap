/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:04:59 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 21:06:15 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*last_node;

	if (!head || !*head || !(*head)->next)
		return ;
	last_node = find_last(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
