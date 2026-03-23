#include "../../push_swap.h"


void	set_current_index(t_stack *stack)
{
	int i;
	int median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack *target_node;
	long long best_match_index;

	while (a)
	{
		best_match_index = -2147483649;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == -2147483649)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_push_cost(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;
	int cost_a;
	int cost_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			cost_a = a->index;
		else
			cost_a = len_a - (a->index);
		if (a->target_node->above_median)
			cost_b = a->target_node->index;
		else
			cost_b = len_b - (a->target_node->index);
		if (a->above_median && a->target_node->above_median)
			a->push_cost = (cost_a > cost_b) ? cost_a : cost_b;
		else if (!(a->above_median) && !(a->target_node->above_median))
			a->push_cost = (cost_a > cost_b) ? cost_a : cost_b;
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long cheapest_value;
	t_stack *cheapest_node;

	if (!stack)
		return ;
	cheapest_value = 2147483648;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack->cheapest = 0;
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	set_current_index(a);
	set_current_index(b);
	set_target_a(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}
