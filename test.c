/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:33:01 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/01/19 20:33:04 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct s_list
{
	int	value;
	size_t	index;
	size_t	cost;
	bool	is_above_median;
	bool	is_cheapest;
	struct s_list	*next;
	struct s_list *target;
}	s_list;

void	free_stack(struct s_list **stack)
{
	struct s_list *current;
	struct s_list *to_be_freed;
	
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

int	zero_case(char *arg)
{
	size_t	i;
	
	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (arg[i] != '0' || i == 1)
			return (0);
		i++;
	}
	return (1);
}

char	*create_single_arg(char *args)
{
	char	*arg;
	size_t	i;
	
	if (!args)
		return (NULL);
	i = 0;
	while (args[i] != ' ' && args[i] != '\0')
		i++;
	arg = (char *)malloc((i + 1) * sizeof(char));
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

static int	calc_sum(char *str, int is_neg)
{
	size_t	i;
	long long	sum;

	i = 0;
	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (i > 0)
			sum *= 10;
		sum += (str[i] - 48);
		i++;
	}
	if (is_neg)
		sum *= -1;
	if (sum > 2147483647 || sum < -2147483647)
		return (0);
	return ((int)sum);
}

int	ft_atoi(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (calc_sum((char *)&str[i + 1], 1));
		if (str[i] == '+')
			return (calc_sum((char *)&str[i + 1], 0));
		if (str[i] == '\v' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == 32)
			return (0);
		else
			return (calc_sum((char *)&str[i], 0));
	}
	return (0);
}

int	check_for_dubs(struct s_list **stack, int new_value)
{
	int	i;
	struct	s_list *current;
	
	if (!*stack)
		return (1);
	current = *stack;
	while (current)
	{
		if (current->value == new_value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	add_node(struct s_list *new_node, struct s_list **stack)
{
	struct s_list *current;
		
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;

}

struct s_list	*create_node(char *arg, struct s_list **stack)
{
	struct s_list *new_node;
	int	val;
	
	if (zero_case(arg))	
		val = 0;
	else
	{
		val = ft_atoi(arg);
		if (!val)
			return (NULL);
	}
	if(!check_for_dubs(stack, val))
		return (NULL);
	new_node = (struct s_list *)malloc(sizeof(struct s_list));
	if (!new_node)
		return (NULL);
	new_node->value = val;
	return (new_node);
}

void	swap(struct s_list **stack)
{
	int	temp;
	struct s_list *head = *stack;
	
	temp = head->next->value;
	head->next->value = head->value;
	head->value = temp;
}

void	push(struct s_list **dest, struct s_list **src)
{
	struct s_list *node;

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

void	rotate_stack(struct s_list **stack)
{
	struct s_list *head;
	struct s_list *newhead;
	struct s_list *current;
	
	current = *stack;
	head = *stack;
	while (current->next)
		current = current->next;
	newhead = head->next;
	head->next = NULL;
	current->next = head;
	*stack = newhead;
}

void	reverse_rotate(struct s_list **stack)
{
	struct s_list *current;
	struct s_list *last;
	struct s_list *head;
	
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

struct s_list	*get_min(struct s_list *stack)
{
	struct s_list	*min;
	
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

struct s_list	*get_max(struct s_list *stack)
{
	struct s_list	*max;
	
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

size_t	get_len(struct s_list **stack)
{
	size_t	len;
	struct s_list *current;
	
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

int	rrb(struct s_list **stack_a)
{
	reverse_rotate(stack_a);
	return (write(1, "rrb\n", 4));
}

int	rra(struct s_list **stack_a)
{
	reverse_rotate(stack_a);
	return (write(1, "rra\n", 4));
}
int	rrr(struct s_list **stack_a, struct s_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (write(1, "rrr\n", 4));
}
int	pb(struct s_list **stack_a, struct s_list **stack_b)
{
	if(!*stack_a)
		return (0);
	push(stack_b, stack_a);
	return (write(1, "pb\n", 3));
}

int	pa(struct s_list **stack_a, struct s_list **stack_b)
{
	if (!*stack_b)
		return (0);
	push(stack_a, stack_b);
	return (write(1, "pa\n", 3));
}

int	rb(struct s_list **stack_a)
{
	    rotate_stack(stack_a);
	    return (write(1, "rb\n", 3));
}

int	ra(struct s_list **stack_a)
{
	    rotate_stack(stack_a);
	    return (write(1, "ra\n", 3));
}

int	rr(struct s_list **stack_a, struct s_list **stack_b)
{
	int	i;
	int	j;
	
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	return (write(1, "rr\n", 3));
}

int	sa(struct s_list **stack_a)
{
	swap(stack_a);
	return (write(1, "sa\n", 3));
}

void	add_indexes(struct s_list *stack)
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
		if (i >= med)
			stack->is_above_median = true;
		i++;
		stack = stack->next;
	}
}
	
void	set_targets(struct s_list *a, struct s_list *b)
{
	long	match;
	struct s_list	*target;
	struct s_list	*current;

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
size_t	calc_discount(size_t i1, size_t i2)
{
	size_t	greater;
	size_t	lesser;
	size_t	res;
	
	if (i1 >= i2)
	{
		greater = i1;
		lesser = i2;
	}
	else
	{
		greater = i2;
		lesser = i1;
	}
	res = greater - lesser;
	return (res);
}

void	set_costs(struct s_list *stack_a, struct s_list *stack_b)
{
	size_t	b_len;
	size_t	a_len;
	size_t	discount;
	
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
		if (stack_b->is_above_median && stack_b->target->is_above_median)
		{
			discount = calc_discount(stack_b->index, stack_b->target->index);
			stack_b->cost -= discount;	
		}
		else if (!stack_b->is_above_median && !stack_b->target->is_above_median)
		{
			discount = calc_discount(stack_b->index, stack_b->target->index);
			stack_b->cost -= discount;	
		}
		stack_b = stack_b->next;
	}	
}

void	set_cheapest(struct s_list *stack_b)
{
	struct s_list	*cheapest;
	long	lowest_cost;
	
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

struct s_list	*find_cheapest(struct s_list **stack)
{
	struct s_list	*current;
	
	current = *stack;
	while (current)
	{
		if (current->is_cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int	solve_three(struct s_list **stack_a)
{
	struct s_list *max;
	int	i;
	
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

size_t move_index(char *arg)
{
	size_t	i;
	if (!arg)
		return (0);
	i = 0;
	while (arg[i] != ' ' || arg[i + 1] != '\0')
		i++;
	return (i);
}

struct s_list *create_arg_list(char *args, struct s_list *stack)
{
	struct s_list *new_node;
	char	*arg;
	size_t	i;
	int	val;
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
		if (!new_node)
		{
			free(arg);
			free_stack(&stack);
			return (NULL);
		}
		if (!stack)
			stack = new_node;
		else
			add_node(new_node, &stack);
			
		while (args[i] != ' ' && args[i + 1] != '\0')
			i++;
		i++;
	}
	return (stack);
}

int	rotate_both(struct s_list **a, struct s_list **b, struct s_list *cheapest)
{
	int	i;
	
	i = 1;
	while (*a != cheapest->target && *b != cheapest && i != -1)
		i = rr(a, b); 
	add_indexes(*a);
	add_indexes(*b);
	return (i);
}

int	rr_both(struct s_list **a, struct s_list **b, struct s_list *cheapest)
{
	int	i;
	
	i = 1;
	while (*a != cheapest->target && *b != cheapest && i != -1)
		i = rrr(a, b); 
	add_indexes(*a);
	add_indexes(*b);
	return (i);
}

int	handle_a(struct s_list **a, struct s_list *target)
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

int	handle_b(struct s_list **a, struct s_list *target)
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

int	mover(struct s_list **a, struct s_list **b)
{
	int	i;
	int	j;
	struct	s_list *cheapest;
	
	cheapest = find_cheapest(b);
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		i = rotate_both(a, b, cheapest);
	else if (cheapest->is_above_median == false && cheapest->target->is_above_median == false)
		i = rr_both(a, b, cheapest);
	if (i == -1)
		return (i);
	i = handle_a(a, cheapest->target);
	j = handle_b(b, cheapest);
	if (i == -1 || j == -1)
		return (-1);
	i = pa(a, b);
	return (i);
}

void	init_stacks(struct s_list *stack_a, struct s_list *stack_b)
{
	add_indexes(stack_a);
	add_indexes(stack_b);
	set_targets(stack_a, stack_b);
	set_costs(stack_a, stack_b);
	set_cheapest(stack_b);
}

int	handle_five(struct s_list **a, struct s_list **b)
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

int	check_if_sorted(struct s_list **stack)
{
	struct	s_list *current;
	int	min_value;
	
	if (!stack)
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
int	handle_rest(struct s_list **a)
{
	int	i;
	struct s_list	*min;
	
	add_indexes(*a);
	min = get_min(*a);
	if (min->is_above_median)
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

int	solver(struct s_list **a, struct s_list **b)
{
	size_t	len;
	int	i;
	
	len = get_len(a);
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
	if (i == -1)
		return (-1);
	while (*b)
	{
		init_stacks(*a, *b);
		i = mover(a, b);
		if (i == -1)
			return (i);
	}
	i = handle_rest(a);
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	struct s_list	*stack_a;
	struct s_list	*stack_b;

	if (argc != 2 || !argv[1])
	{
		write(2, "Error\n", 6);
		return (0); 
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_arg_list(argv[1], stack_a);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0); 
	}
	if (get_len(&stack_a) == 1 || check_if_sorted(&stack_a))
	{
		return (1);
	}
	i = solver(&stack_a, &stack_b);
	if (i == -1)
	{
		if (stack_b)
			free_stack(&stack_b);
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
