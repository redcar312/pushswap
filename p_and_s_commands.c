/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_and_s_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:40:41 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 17:41:02 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(struct t_list **stack_a)
{
	swap(stack_a);
	return (write(1, "sa\n", 3));
}

int	pb(struct t_list **stack_a, struct t_list **stack_b)
{
	if (!*stack_a)
		return (0);
	push(stack_b, stack_a);
	return (write(1, "pb\n", 3));
}

int	pa(struct t_list **stack_a, struct t_list **stack_b)
{
	if (!*stack_b)
		return (0);
	push(stack_a, stack_b);
	return (write(1, "pa\n", 3));
}

size_t	move_index(char *args)
{
	size_t	i;

	i = 0;
	while (args[i] != ' ' && args[i + 1] != '\0')
		i++;
	return (i);
}
