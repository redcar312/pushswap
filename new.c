
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct s_list
{
	int	value;
	size_t	index;
	size_t	cost;
	int	is_above_median;
	int is_cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	s_list;

#include <unistd.h>
#include <stdlib.h>

void	swap(struct s_list **stack)
{
	struct s_list *head:
	int temp;

	if (!*stack)
		return ;
	head = *stack;
	if (!head->next)
		return ;
	temp = head->value;
	head->value = head->next->value;
}

void	rotate(struct s_list **stack)
{
	struct s_list *current;
	struct s_list *head;
	struct s_list *new_head;
	size_t	len;

	if (!*stack || !stack || len <= 1)
		return ;
	current = *stack;
	while(current->next)
		current = current->next;
	head = *stack;
	new_head = head->next;
	current->next = head;
	head->prev = current;
	head->next = NULL;
	new_head->prev = NULL;
	*stack = new_head;
}

void reverse_rotate(struct s_list **stack)
{
	struct	s_list	*current;
	struct	s_list	*head;
	struct	s_list	*last;
	size_t	len;

	if(!*stack || !stack || len <= 1)
		return ;
	head = *stack;
	current = *stack;
	while(current->next)
		current = current->next;
	last = current->prev;
	last->next = NULL;
	current->prev = NULL;
	current->next = head;
	head->prev = current;
	*stack = current;
}


void	push(struct s_list **dest, struct s_list **src)
{
	struct s_list *dest_head;
	struct s_list *src_head;

	if (!*src)
		return ;
	src_head = *src;
	src_head->is_cheapest = 0;
	if (src_head->next)
	{
		*src = src_head ->next;
		*src->prev = NULL;
		src_head->next = NULL;
	}
	if (!*dest)
	{
		*dest = src_head;
		return ;
	}
	dest_head = *dest;
	dest_head->prev = src_head;
	src_head->next = dest_head;
	*dest = src_head;
};

void	pb(struct s_list **stack_a, struct s_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	pa(struct s_list **stack_a, struct s_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}
void	rb(struct s_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);

}
void	rrb(struct s_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);

}
void	ra(struct s_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);

}

void	rra(struct s_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rra\n", 4);

}

void	rr(struct s_list *stack_a, struct s_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);

}

void	rrr(struct s_list *stack_a, struct s_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);

}

void	rotate_both(struct s_list **stack_a, struct s_list **stack_b, struct s_list *cheapest)  
{
	while(*stack_a != cheapest->target_node && *stack_b != cheapest)
		rr(stack_a, stack_b);
	add_indexes(stack_a);
	add_indexes(stack_b);
}

void	rr_both(struct s_list **stack_a, struct s_list **stack_b, struct s_list *cheapest)  
{
	while(*stack_a != cheapest->target_node && *stack_b != cheapest)
		rrr(stack_a, stack_b);
	add_indexes(stack_a);
	add_indexes(stack_b);
}

size_t get_len(struct s_list **stack)
{
	size_t	len;
	struct	s_list	*current;

	if(!*stack)
		return (0);
	len = 1;
	current = *stack;
	while (current->next)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	find_max(struct s_list *stack)
{
	int	max;

	if (!*stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if(stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

struct s_list	*find_min(struct s_list *stack)
{
	int	min;
	struct s_list	*lowest;
	if (!*stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			lowest = stack;
		}
		stack = stack->next;
	}
	return (lowest);
}

void	add_indexes(struct s_list *stack)
{
	size_t	i;
	size_t	med;
	size_t	len;
	i = 0;
	if (!*stack)
		return ;

	len = get_len(&stack);
	med = len \ 2;
	while (stack)
	{
		stack->index = i;
		if(i > len)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		i++;
		stack = stack->next;
	}
}

void set_costs(struct s_list *stack_a, struct s_list *stack_b)
{
	size_t	a_len;
	size_t	b_len;

	a_len = get_len(&stack_a);
	b_len = get_len(&stack_b);
	while (stack_b)
	{
		stack_b->cost = stack_b->index
		if(stack_b->is_above_median)
			stack_b->cost = b_len - stack_b->cost;
		if(!stack_b->target_node->is_above_median)
			stack_b->cost += stack_b->target_node->index;
		else
			stack_b->cost += a_len - stack_b->target_node->index;
		stack_b = stack_b->next;

	}
}

void	set_cheapest(struct s_list *stack)
{
	size_t	cheapest;
	struct s_list *cheapest_node;

	cheapest = SIZE_MAX;
	while(stack)
	{
		if(stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = 1;
}
struct s_list	*find_cheapest(struct s_list *stack)
{
	struct s_list *cheapest_node;
	if(!stack)
	{
		return (NULL);
	}
	cheapest_node = NULL;
	while(stack)
	{
			if(stack->is_cheapest)
				cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

void	set_targets(struct s_list **stack_a, struct s_list **stack_b)
{
	struct s_list *current;
	long	best_match;
	struct s_list	*target;

	while (b)
	{
		best_match = LONG_MAX;
		current = *stack_a;
		while (current)
		{
			if (current->value > b->value && current->value < best_match)
			{
				best_match = (long)current->value;
				target = current;
			}
			current = current->next;
		}
	}
	if (best_match == LONG_MAX)
		target = find_min(stack_a);
	b->target = target;
	b = b->next;
}

void	handle_rotation_b(struct s_list **stack, struct s_list *target)
{	
		if(target->is_above_median)
	{
		while(*stack != target)
			rrb(stack);
	}
	else
	{
		while(*stack != target)
			rb(stack);
	}
}
void	handle_rotation_a(struct s_list **stack, struct s_list *target)
{	
		if(target->is_above_median)
	{
		while(*stack != target)
			rra(stack);
	}
	else
	{
		while(*stack != target)
			ra(stack);
	}
}

void	move_nodes(struct s_list **stack_a, struct s_list **stack_b)
{
		struct	s_list *cheapest_node;
		cheapest_node = find_cheapest(stack_b);
		if(!cheapest)
			return ;
		if(!cheapest_node->is_above_median && !cheapest_node->target_node->is_above_median)
			rotate_both(stack_a, stack_b, cheapest_node);
		else if(cheapest_node->is_above_median && cheapest_node->target_node->is_above_median)
			rr_both(stack_a, stack_b, cheapest_node);
		handle_rotation_a(stack_a, cheapest_node->target_node);
		handle_rotation_b(stack_b, cheapest_node);
		pa(stack_a, stack_b);
}
void init_stacks(struct s_list *stack_a, struct s_list *stack_b)
{
	add_indexes(stack_a);
	add_indexes(stack_b);
	set_targets(stack_a, stack_b);
	set_costs(stack_a, stack_b);
	set_cheapest(stack_b);
}

void	sort_three(struct s_list **stack_a)
{
	int	max;

	max = find_max(stack_a);
	if(*stack_a->value == max)
		ra(stack_a);
	else if((*stack_a)->next->value == max)
		rra(stack_a)
	if((*stack_a)->next->value < (*stack_a)->value)
		sa(stack_a);
}
void handle_five(struct s_list **stack_a, struct s_list **stack_b)
{
	while(get_len(stack_a) > 3)
	{
		init_stacks(stack_a, stack_b);
		handle_rotation_a(stack_a, find_min(stack_a));
		pb(stack_a, stack_b);
	}
}

void	sort(struct s_list **stack_a, struct s_list **stack_b)	
{
	struct s_list *min;
	size_t	a_len;

	if(len == 5)
	{
		handle_five(stack_a, stack_b);
	}
	else
	{
		while(a_len-- > 3)
			pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while(*stack_b)
	{
		init_stacks(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	add_indexes(stack_a);
	min = find_min(stack_a);
	if(min->is_above_median)
		while(*stack_a != min)
			rra(stack_a);
	else
		while(*stack_a != min)
			ra(stack_a);
}