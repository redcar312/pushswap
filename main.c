/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:50:12 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/01/10 18:32:24 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(struct s_list **stack)
{
	int	temp;
	struct s_list *head = *stack;
	
	temp = head->next->value;
	head->next->value = head->value;
	head->value = temp;

}

void	push(struct s_list **a, struct s_list **b)
{
	struct s_list *ahead;
	struct s_list *bhead;
	struct s_list *newhead;
	
	newhead = *b;
	bhead = newhead->next;
	if(
	ahead = *a;
	ahead->prev = newhead;
	newhead->next = ahead;
	bhead->prev = NULL;
	*a = newhead;
	*b = bhead; 
}


void	rotate_stack(struct s_list **stack);
{
	struct s_list *head;
	struct s_list *newhead;
	struct s_list *current;
	
	current = *stack;
	while (current->next)
		current = current->next;
	head = *stack;
	last = current;
	newhead = head->next;
	newhead->prev = NULL;
	head->next = NULL;
	head->prev = last;
	last->next = head;
	*stack = newhead;
	
	
}

void	reverse_rotate_stack(struct s_list **stack)
{
	struct s_list *current;
	struct s_list  *second_last;
	struct s_list  *head;	
	
	current = *stack;
	while (current->next)
		current = current->next;
	second_last = current->prev;
	head = *stack;
	current->prev = NULL;
	second_last->next = NULL;
	current->next = head;
	head->prev = current;
	*stack = current;
}

int	get_min(struct s_list **stack)
{
	struct s_list *current;
	int	min;
	
	current = *stack;
	min = current->value;
		
	while (current->next)
	{
		if(current->value < min)
			min = current->value;
		current = current->next;	
	}
	return (min);
}

int	get_max(struct s_list **stack)
{
	struct s_list *current;
	int	max;

	max = current->value;
	while (current->next)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	check_if_sorted(struct s_list **stack)
{
	struct	s_list *current;
	int	min_value;
	
	current = *stack;
	min_value = current->value;	
	while (current->next)
	{
		if (current->value < min_value)
			return (0);
		min_value = current->value;
		current = current->next;
	}	
	return (1);
}

int	check_if_reverse_sorted(struct s_list **stack)
{
	int	max;
	struct s_list	*current;
	
	if (!stack)
		return (0);
	current = *stack;
	max = current->value;
	while (current->next)
	{
		if (current->value > max)
			return (0);
		max = current->value;
		current = current->next;
	}
	return (1);
}

size_t	get_stack_len(struct s_list **stack)
{
	size_t	len;
	struct s_list *current;
	
	if (!stack)
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

int	get_last_node_val(struct s_list **stack)
{
	struct s_list *current;
	
	if (!stack)
		return (0);
	while (current->next)
		current = current->next;
	return (current->value);
}

int	get_head_val(struct s_list **stack)
{
	struct s_list	*head;
	
	head = *stack;
	return (head->value);
}

size_t	get_min_pos(struct s_list **stack, int min)
{
	struct s_list *current;
	size_t	pos;
	
	pos = 1;
	current = *stack;
	while (current->value != min)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void rra(struct s_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void pb(struct s_list **stack_a, struct s_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void pa(struct s_list **stack_a, struct s_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void rra_and_pb(struct s_list **stack_a struct s_list **stack_b, int min)
{
	while (get_head_val(stack_a) != min)
		rra(stack_a);	
	pb(stack_a, stack_b);
}

void pusher(struct s_list **stack_a, struct s_list **stack_b, size_t stack_length)
{
	while(get_stack_len(stack_a) > stack_length)
		pa(stack_a, stack_b);
}

void rotate_and_pb(struct s_list **stack_a, struct s_list **stack_b, int min)
{
	while (get_head_val(stack_a) != min)
		rotate_stack(stack_a);
	pb(stack_a, stack_b);

}
void sa(struct s_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

int will_swap(struct s_list **stack, int min)
{
	struct s_list *head;
	struct s_list *second_node;
	  
	int next_lowest;
	head = *stack;
	if (!head->next || head->value != min)
		return (0);
	second_node = head->next;
	next_lowest = get_min_val(&second_node);
	if (head->value == min || second_node->value == next_lowest)
		return (1);
	return (0);
}

void	solver(struct s_list **stack_a, struct s_list **stack_b, size_t stack_length)
{
	int	max;
	int	min;
	int	current_min;
	int	pos;
	
	max = get_max(stack_a);
	min = get_min(stack_a);
	while (!check_if_sorted(stack_a) && get_stack_len(stack_a) != stack_length)
	{
		current_min = get_min_val(stack_a);
		pos = get_min_pos(stack_a, current_min);
		if (get_head_val(stack_a) == max && get_last_node_val(stack_a) == min)
			rra(stack_a);
		else if (will_swap(stack_a))
			sa(stack_a);
		else if (check_if_sorted(stack_a) && check_if_reverse_sorted(stack_b))
			pusher(stack_a, stack_b);
		else if (pos > (stack_length / 2))
			rra_and_pb(stack_a, stack_b, current_min);
		else if (pos <= (stack_length / 2))
			rotate_and_pb(stack_a, stack_b, current_min);
	}	

}

int	main()
{
	int a[] = {5, 0, 9, 1, 95};
	int b[];
	int	min;
	int	max;
		
	max = get_max(a);
	min = get_min(a);
	sort(a, b, min, max);		
}
