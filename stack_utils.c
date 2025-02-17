/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:43:03 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:43:22 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(struct t_list **stack)
{
	struct t_list	*current;
	struct t_list	*to_be_freed;

	if (!*stack)
		return ;
	current = *stack;
	if (!current->next)
		free(current);
	else
	{
		while (current->next)
		{
			to_be_freed = current;
			current = current->next;
			free(to_be_freed);
		}
		free(current);
	}
}

struct t_list	*get_min(struct t_list *stack)
{
	struct t_list	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

struct t_list	*get_max(struct t_list *stack)
{
	struct t_list	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

struct t_list	*find_cheapest(struct t_list **stack)
{
	struct t_list	*current;

	current = *stack;
	while (current)
	{
		if (current->is_cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

size_t	get_len(struct t_list **stack)
{
	size_t			len;
	struct t_list	*current;

	if (!*stack)
		return (0);
	current = *stack;
	len = 1;
	while (current->next)
	{
		len++;
		current = current->next;
	}
	return (len);
}
