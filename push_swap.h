/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:15:27 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/30 16:59:29 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* parsing */
int		ft_atol_check(const char *s, long *res);
int		duplicate_error(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
void	init_stack_a(t_stack **a, char **argv, int should_free);
void	free_split(char **args, int should_free);

/* stack utils */
t_stack	*find_last(t_stack *stack);
void	append_node(t_stack **stack, int n);
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack);

/* swap */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* push */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* rotate */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* reverse rotate */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* find */
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);

/* init a */
void	set_target_a(t_stack *a, t_stack *b);
void	set_current_index(t_stack *stack);
void	set_push_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	sort_three(t_stack **a);

/* init b */
void	set_target_b(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);

/* moves */
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	finish_rotation(t_stack **stack, t_stack *top_node,
			char stack_name);
void	move_a_to_b(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

/* sort */
void	turk_sort(t_stack **a, t_stack **b);

#endif