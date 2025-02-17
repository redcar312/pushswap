/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:29:04 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 17:29:24 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_indexes(struct t_list *stack)
{
	size_t	len;
	size_t	i;
	size_t	med;

	if (!stack)
		return ;
	len = get_len(&stack);
	med = len / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		stack->is_above_median = false;
		if (i > med)
			stack->is_above_median = true;
		i++;
		stack = stack->next;
	}
}

void	set_targets(struct t_list *a, struct t_list *b)
{
	long			match;
	struct t_list	*target;
	struct t_list	*current;

	while (b)
	{
		current = a;
		match = LONG_MAX;
		while (current)
		{
			if (current->value > b->value && (long)current->value < match)
			{
				match = (long)current->value;
				target = current;
			}
			current = current->next;
		}
		if (match == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_costs(struct t_list *stack_a, struct t_list *stack_b)
{
	size_t	b_len;
	size_t	a_len;

	if (!stack_b || !stack_a)
		return ;
	a_len = get_len(&stack_a);
	b_len = get_len(&stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->index;
		if (stack_b->is_above_median)
			stack_b->cost = b_len - stack_b->index;
		if (stack_b->target->is_above_median)
			stack_b->cost += a_len - stack_b->target->index;
		else
			stack_b->cost += stack_b->target->index;
		stack_b = stack_b->next;
	}
}

void	set_cheapest(struct t_list *stack_b)
{
	struct t_list	*cheapest;
	long			lowest_cost;

	if (!stack_b)
		return ;
	lowest_cost = LONG_MAX;
	while (stack_b)
	{
		stack_b->is_cheapest = false;
		if ((long)stack_b->cost < lowest_cost)
		{
			cheapest = stack_b;
			lowest_cost = (long)stack_b->cost;
		}
		stack_b = stack_b->next;
	}
	cheapest->is_cheapest = true;
}

void	init_stacks(struct t_list *stack_a, struct t_list *stack_b)
{
	add_indexes(stack_a);
	add_indexes(stack_b);
	set_targets(stack_a, stack_b);
	set_costs(stack_a, stack_b);
	set_cheapest(stack_b);
}
