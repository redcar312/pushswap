/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:35:25 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:35:45 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(struct t_list **stack)
{
	struct t_list	*head;
	struct t_list	*temp;

	head = (*stack)->next;
	temp = *stack;
	temp->next = head->next;
	head->next = temp;
	*stack = head;
}

void	push(struct t_list **dest, struct t_list **src)
{
	struct t_list	*node;

	if (!*src)
		return ;
	node = *src;
	if (!node->next)
		*src = NULL;
	else
		*src = (*src)->next;
	node->next = NULL;
	if (!*dest)
		*dest = node;
	else
	{
		node->next = *dest;
		*dest = node;
	}
}

void	rotate_stack(struct t_list **stack)
{
	struct t_list	*head;
	struct t_list	*newhead;
	struct t_list	*current;

	current = *stack;
	head = *stack;
	while (current->next)
		current = current->next;
	newhead = head->next;
	head->next = NULL;
	current->next = head;
	*stack = newhead;
}

void	reverse_rotate(struct t_list **stack)
{
	struct t_list	*current;
	struct t_list	*last;
	struct t_list	*head;

	if (!*stack)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	current = *stack;
	while (current->next != last)
		current = current->next;
	head = *stack;
	last->next = head;
	current->next = NULL;
	*stack = last;
}
