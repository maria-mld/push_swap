/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:04:18 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 21:54:44 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atol_check(const char *s, long *res)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	if (*s < '0' || *s > '9')
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s++ - '0');
		if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
			return (0);
	}
	if (*s)
		return (0);
	*res = num * sign;
	return (1);
}

int	duplicate_error(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)
{
	if (!a)
		return ;
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_stack_a(t_stack **a, char **argv, int should_free)
{
	long n;
	int i;

	i = 0;
	while (argv[i])
	{
		if (!ft_atol_check(argv[i], &n))
		{
			free_split(argv, should_free);
			free_errors(a);
		}
		if (duplicate_error(*a, (int)n))
		{
			free_split(argv, should_free);
			free_errors(a);
		}
		append_node(a, (int)n);
		i++;
	}
	free_split(argv, should_free);
}