/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:23:47 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:24:22 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static struct t_list	*maker(char **argv, struct t_list *stack)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			free_stack(&stack);
			return (NULL);
		}
		stack = create_arg_list(argv[i], stack);
		if (!stack)
			return (NULL);
		i++;
	}
	return (stack);
}

int	check_if_sorted(struct t_list **stack)
{
	struct t_list	*current;
	int				min_value;

	if (!*stack)
		return (0);
	current = *stack;
	min_value = current->value;
	while (current->next)
	{
		if (current->next->value < min_value)
			return (0);
		min_value = current->next->value;
		current = current->next;
	}
	return (1);
}

static int	sort_handler(struct t_list **stack_a, struct t_list **stack_b)
{
	int	i;

	i = 1;
	if (get_len(stack_a) == 1)
		return (i);
	if (get_len(stack_a) == 2)
		i = sa(stack_a);
	else if (get_len(stack_a) == 3)
		i = solve_three(stack_a);
	else
		i = solver(stack_a, stack_b);
	return (i);
}

static void	err_handler(struct t_list **stack_a, struct t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
}

int	main(int argc, char **argv)
{
	int				i;
	struct t_list	*stack_a;
	struct t_list	*stack_b;

	if (argc == 1)
		exit(0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = maker(argv, stack_a);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (!check_if_sorted(&stack_a))
		i = sort_handler(&stack_a, &stack_b);
	if (i == -1)
	{
		err_handler(&stack_a, &stack_b);
		exit(0);
	}
	free_stack(&stack_a);
	exit(1);
}
