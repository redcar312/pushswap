/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_rotators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:43:16 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 17:43:30 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_b(struct t_list **a, struct t_list **b, struct t_list *c)
{
	int	i;

	i = 1;
	while (*a != c->target && *b != c && i != -1)
		i = rr(a, b);
	add_indexes(*a);
	add_indexes(*b);
	return (i);
}

int	r_r(struct t_list **a, struct t_list **b, struct t_list *c)
{
	int	i;

	i = 1;
	while (*a != c->target && *b != c && i != -1)
		i = rrr(a, b);
	add_indexes(*a);
	add_indexes(*b);
	return (i);
}

int	handle_a(struct t_list **a, struct t_list *target)
{
	int	i;

	i = 1;
	while (*a != target && i != -1)
	{
		if (target->is_above_median)
			i = rra(a);
		else
			i = ra(a);
	}
	return (i);
}

int	handle_b(struct t_list **a, struct t_list *target)
{
	int	i;

	i = 1;
	while (*a != target && i != -1)
	{
		if (target->is_above_median)
			i = rrb(a);
		else
			i = rb(a);
	}
	return (i);
}
