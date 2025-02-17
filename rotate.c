/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:37:13 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:39:43 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(struct t_list **stack_a)
{
	rotate_stack(stack_a);
	return (write(1, "rb\n", 3));
}

int	ra(struct t_list **stack_a)
{
	rotate_stack(stack_a);
	return (write(1, "ra\n", 3));
}

int	rr(struct t_list **stack_a, struct t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	return (write(1, "rr\n", 3));
}
