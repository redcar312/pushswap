/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:26:08 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:26:29 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*create_single_arg(char *args)
{
	char	*arg;
	size_t	i;

	if (!*args)
		return (NULL);
	i = 0;
	if (args[i] < '0' || args[i] > '9')
	{
		if (args[i] != '-' && args[i] != '+')
			return (NULL);
	}
	while (args[i] != ' ' && args[i] != '\0')
		i++;
	arg = (char *)ft_calloc((i + 1), sizeof(char));
	if (!arg)
		return (NULL);
	i = 0;
	while (args[i] != ' ' && args[i] != '\0')
	{
		arg[i] = args[i];
		i++;
	}
	arg[i] = '\0';
	return (arg);
}

void	add_node(struct t_list *new_node, struct t_list **stack)
{
	struct t_list	*current;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

struct t_list	*create_node(char *arg, struct t_list **stack)
{
	struct t_list	*new_node;
	int				val;

	if (zero_case(arg))
		val = 0;
	else
		val = ft_atoi(arg);
	if ((!zero_case(arg) && !val) || !check_for_dubs(stack, val))
	{
		free_stack(stack);
		return (NULL);
	}
	new_node = (struct t_list *)ft_calloc(1, sizeof(struct t_list));
	if (!new_node)
	{
		free_stack(stack);
		return (NULL);
	}
	new_node->value = val;
	return (new_node);
}

static int	checker(struct t_list **stack, size_t i, char *args)
{
	if (args[i] > '9' && args[i] < '0' && args[i + 1] == '\0')
	{
		free_stack(stack);
		return (0);
	}
	return (1);
}

struct t_list	*create_arg_list(char *args, struct t_list *stack)
{
	struct t_list	*new_node;
	char			*arg;
	size_t			i;

	i = 0;
	while (args[i])
	{
		arg = create_single_arg(&args[i]);
		if (!arg)
		{
			free_stack(&stack);
			return (NULL);
		}
		new_node = create_node(arg, &stack);
		free(arg);
		if (!new_node)
			return (NULL);
		add_node(new_node, &stack);
		i += move_index(&args[i]);
		if (!checker(&stack, i, args))
			return (NULL);
		i++;
	}
	return (stack);
}
