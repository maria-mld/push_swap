/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:51:34 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 21:55:07 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	ft_memset(node, 0, sizeof(t_stack));
	node->value = n;
	if (!*stack)
		*stack = node;
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->prev = last;
	}
}

int	stack_len(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
int	stack_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	free_split(char **args, int should_free)
{
	int	i;

	i = 0;
	if (!args || (args && !should_free))
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}