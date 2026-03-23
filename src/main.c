/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:26:12 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 22:02:04 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

static void	sort_handle(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		turk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (!argv)
		return (write(2, "Error\n", 6), 1);
	if (!argv[0])
		return (write(2, "Error\n", 6), free_split(argv, 1), 1);
	init_stack_a(&a, argv, argc == 2);
	if (!stack_sorted(a))
		sort_handle(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
