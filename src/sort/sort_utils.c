/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:07:23 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 21:07:23 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (stack_sorted(*a))
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

t_stack	*find_max(t_stack *stack)
{
	long long	max;
	t_stack		*max_node;

	if (!stack)
		return (NULL);
	max = -2147483649;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	long long	min;
	t_stack		*min_node;

	min_node = NULL;
	if (!stack)
		return (NULL);
	min = 2147483648;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
