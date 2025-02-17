/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:41:02 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:41:21 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrb(struct t_list **stack_a)
{
	reverse_rotate(stack_a);
	return (write(1, "rrb\n", 4));
}

int	rra(struct t_list **stack_a)
{
	reverse_rotate(stack_a);
	return (write(1, "rra\n", 4));
}

int	rrr(struct t_list **stack_a, struct t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (write(1, "rrr\n", 4));
}
