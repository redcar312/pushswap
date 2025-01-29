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
#include <stdio.h>

struct s_list
{
	int	value;
	struct s_list	*next;
}	s_list;

#include <unistd.h>
#include <stdlib.h>

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
	if (!current->next)
		return (1);
	while (current->next)
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
	{	
		val = 0;
		if (check_for_dubs(stack, val))
			return (NULL);
	}
	else
	{
		val = ft_atoi(arg);
		if (!val)
			return (NULL);
	}
	
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

void	push(struct s_list **a, struct s_list **b)
{
	struct s_list *ahead;
	struct s_list *bhead;
	struct s_list *newhead;
	
	newhead = *b;
	bhead = newhead ->next;
	ahead = *a;
	newhead->next = ahead;
	*a = newhead;
	*b = bhead;
	 int i = newhead->value;
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

void	reverse_rotate_stack(struct s_list **stack)
{
	struct s_list *current;
	struct s_list *last;
	struct s_list *head;
	current = *stack;
	head = *stack;
	while (current->next->next != NULL)
	    current = current->next;
	last = current->next;
	last->next = head;
	current->next = NULL;
	*stack = last;
}

int	get_min(struct s_list **stack)
{
	struct s_list *current;
	int	min;
	
	current = *stack;
	min = current->value;	
	while (current->next)
	{
		if (min > current->next->value)
			min = current->next->value;
		current = current->next;	
	}
	return (min);
}

int	get_max(struct s_list **stack)
{
	struct s_list *current;
	int	max;

	current = *stack;
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

int	check_if_reverse_sorted(struct s_list **stack)
{
	int	max;
	struct s_list	*current;
	
	if (!*stack)
		return (0);
	current = *stack;
	max = current->value;
	while (current->next)
	{
		if (current->next->value > max)
			return (0);
		max = current->next->value;
		current = current->next;
	}
	return (1);
}

size_t	get_stack_len(struct s_list **stack)
{
	size_t	len;
	struct s_list *current;
	
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

int	rra(struct s_list **stack_a)
{
	reverse_rotate_stack(stack_a);
	return (write(1, "rra\n", 4));
}

int	pb(struct s_list **stack_a, struct s_list **stack_b)
{
	push(stack_b, stack_a);
	return (write(1, "pb\n", 3));
}

int	pa(struct s_list **stack_a, struct s_list **stack_b)
{
	push(stack_a, stack_b);
	return (write(1, "pa\n", 3));
}

int	rra_and_pb(struct s_list **stack_a, struct s_list **stack_b, int min)
{
	int	i;
	
	while (get_head_val(stack_a) != min)
	{
		i = rra(stack_a);
		if (i == -1)
			return (i);
	}	
	i = pb(stack_a, stack_b);
	return (i);
}

int	pusher(struct s_list **stack_a, struct s_list **stack_b)
{
	int	i;
	
	while (*stack_b)
	{
		i = pa(stack_a, stack_b);
		if (i == -1)
			return (i);
	}
	return (i);
}

int	ra(struct s_list **stack_a)
{
	    rotate_stack(stack_a);
	    return (write(1, "ra\n", 3));
}

int	rotate_and_pb(struct s_list **stack_a, struct s_list **stack_b, int min)
{
	int	i;
	
	while (get_head_val(stack_a) != min)
	{
	    i = ra(stack_a);
	    if (i == -1)
	    	return (-1);
	}
	i = pb(stack_a, stack_b);
	return (i);
}

int	sa(struct s_list **stack_a)
{
	swap(stack_a);
	return (write(1, "sa\n", 3));
}

int	get_second_lowest(struct s_list **astack, int min)
{
	int	second_lowest;
	struct s_list	*stack;

	if (!*astack)
		return (0);
	stack = *astack;
	if (stack->value == min)
	    return (0);
	if(!stack->next || stack->next->value != min)
	    return (0);
	second_lowest = stack->value + min;
	while (stack->next)
	{
	    if(stack->value == min)
	        stack = stack->next;
	    else
	    {
		    if (stack->value + min < second_lowest)
			    return (0);
            stack = stack->next;
	    }
	}
	return (1);
}

int will_swap(struct s_list **stack, int min)
{
	struct s_list *head;
	  
	int next_lowest = get_second_lowest(stack, min);
	if (!*stack)
		return (0);
	head = *stack;
	if (!head->next || head->next->value != min)
		return (0);
	if (!head->next)
		return (0);
	if (head->value == next_lowest)
		return (1);
	return (0);
}

size_t	find_pivot_index(struct s_list **stack, int pivot)
{
	struct s_list *current;
	size_t	i;
	
	if (!*stack)
		return (0);
	current = *stack;
	i = 1;
	while (current->next)
	{
		if (current->value == pivot)
			return (i);
		i++;
		current = current->next;
	}
	return (i);
}

ssize_t	find_pos(struct s_list **stack, size_t start_index, int pivot)
{
	int	i;
	struct s_list	*current;
	
	if (*!stack)
		return (0);
	i = 1;
	if (start_index != 1)
	{
		while (current->value != pivot)
			current = current->next;
	}
	while (current->next)
	{
		if (current->value > pivot)
			return (i);
		i++;
		current = current->next; 
	}
	return (i);
}

void	partition_stack(struct s_list **stack_a, struct s_list **stack_b, int pivot)
{
	int	i;
	int	current_max;
	int	pivot_index;
	ssize_t	cheapest;
	
	i = 1;
	while (pivot != get_max(stack_a) && i != -1)
	{
		
	}
}

void	solver(struct s_list **stack_a, struct s_list **stack_b, int min, int max, size_t stack_len)
{
	int	pivot;

	if (max < 0)
		pivot = ((max * -1) - (min * -1)) * -1;
	else
		pivot = max - min;
}


/*int	solver(struct s_list **stack_a, struct s_list **stack_b, size_t stack_length, int min, int max)
{
	int	current_min;
	int	pos;
	size_t len;
	int	i;
	
	i = 1;
	while (i != -1)
	{
		if (check_if_sorted(stack_a) && get_stack_len(stack_a) == stack_length)
			return (i);
		current_min = get_min(stack_a);
		pos = get_min_pos(stack_a, current_min);
		len = get_stack_len(stack_a);
		if (check_if_sorted(stack_a) == 1 && check_if_reverse_sorted(stack_b) == 1)
		{
			i = pusher(stack_a, stack_b);
			return (i);
		}
		if (get_head_val(stack_a) == max && get_last_node_val(stack_a) == min)
			i = rra(stack_a);
	    if (get_second_lowest(stack_a, current_min) && i != -1)
			i = sa(stack_a);
	    else if (pos > (len / 2) && i != -1)
			i = rra_and_pb(stack_a, stack_b, current_min);
		else if (pos <= (len / 2) && i != -1)
			i = rotate_and_pb(stack_a, stack_b, current_min);
	}
	return (i);
}
*/
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
			
		while(args[i] != ' ' && args[i + 1] != '\0')
			i++;
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int	min;
	int	max;
	size_t	stack_len;
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
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	max = get_max(&stack_a);
	min = get_min(&stack_a);
	stack_len = get_stack_len(&stack_a);
	if (solver(&stack_a, &stack_b, stack_len, min, max))
        {
           return (1);
        }
}
