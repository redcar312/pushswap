/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:24:05 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 17:24:31 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve_three(struct t_list **stack_a)
{
	struct t_list	*max;
	int				i;

	max = get_max(*stack_a);
	i = 1;
	if ((*stack_a) == max && i != -1)
		i = ra(stack_a);
	else if ((*stack_a)->next == max && i != -1)
		i = rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value && i != -1)
		i = sa(stack_a);
	return (i);
}

int	mover(struct t_list **a, struct t_list **b)
{
	int				i;
	int				j;
	struct t_list	*cheapest;

	cheapest = find_cheapest(b);
	i = 1;
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		i = r_r(a, b, cheapest);
	else if (!cheapest->is_above_median && !cheapest->target->is_above_median)
		i = r_b(a, b, cheapest);
	if (i == -1)
		return (i);
	i = handle_a(a, cheapest->target);
	j = handle_b(b, cheapest);
	if (i == -1 || j == -1)
		return (-1);
	i = pa(a, b);
	return (i);
}

int	handle_rest(struct t_list **a)
{
	int				i;
	struct t_list	*min;

	add_indexes(*a);
	min = get_min(*a);
	if (*a)
	{
		while (*a != min && i != -1)
			i = rra(a);
	}
	else
	{
		while (*a != min && i != -1)
			i = ra(a);
	}
	return (i);
}

int	handle_five(struct t_list **a, struct t_list **b)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (get_len(a) > 3)
	{
		add_indexes(*a);
		i = handle_a(a, get_min(*a));
		j = pb(a, b);
		if (i == -1 || j == -1)
			return (-1);
	}
	return (i);
}

int	solver(struct t_list **a, struct t_list **b)
{
	size_t	len;
	int		i;

	len = get_len(a);
	i = 1;
	if (len == 5)
		i = handle_five(a, b);
	else
	{
		while (len-- > 3 && i != -1)
			i = pb(a, b);
	}
	if (i == -1)
		return (i);
	i = solve_three(a);
	while (*b && i != -1)
	{
		init_stacks(*a, *b);
		i = mover(a, b);
	}
	if (i == -1)
		return (i);
	i = handle_rest(a);
	return (i);
}
