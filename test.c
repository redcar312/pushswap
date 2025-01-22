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
		sum *= -1
	if(sum > 2147483647 || sum < -2147483647)
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
			i++;
		else
			return (calc_sum((char *)&str[i], 0));
	}
	return (0);
}
int	check_for_dubs(struct s_list **stack, int new_value)
{
	int	i;
	struct	s_list *current;
	
	if(!*stack)
		return (1);
	if(!current->next)
		return (1);
	while(current->next)
	{
		if(current->value == new_value)
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

struct s_list	*create_node(int value)
{
	struct s_list *new_node;
	
	new_node = (struct s_list *)malloc(sizeof(struct s_list));
	if(!new_node)
		return (NULL);
	new_node->value = value;
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
		if(min > current->next->value)
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
	
	if(!stack)
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

void rra(struct s_list **stack_a)
{
	reverse_rotate_stack(stack_a);
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

void rra_and_pb(struct s_list **stack_a, struct s_list **stack_b, int min)
{
	while (get_head_val(stack_a) != min)
		rra(stack_a);	
	pb(stack_a, stack_b);
}

void pusher(struct s_list **stack_a, struct s_list **stack_b)
{
	while(*stack_b)
		pa(stack_a, stack_b);
}

void rotate_and_pb(struct s_list **stack_a, struct s_list **stack_b, int min)
{
	while (get_head_val(stack_a) != min)
	{
	    write(1, "ra\n", 3);
	    rotate_stack(stack_a);
	}
	pb(stack_a, stack_b);

}

void sa(struct s_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

int get_second_lowest(struct s_list **astack, int min)
{
    int second_lowest;
    struct s_list *stack;
    
    stack = *astack;
    second_lowest = stack->value + min;
    stack = stack->next->next;
    while(stack->next)
    {
                    
            if(stack->value + min < second_lowest)
                return(0);
            stack = stack->next;
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
	if(!head->next || head->next->value != min)
	    return(0);
	if (!head->next)
		return (0);
	if (head->value == next_lowest)
		return (1);
	return (0);
}

void	solver(struct s_list **stack_a, struct s_list **stack_b, size_t stack_length, int min, int max)
{
	int	current_min;
	int	pos;
	int i = 1;
	size_t len;
	int t;
	struct s_list *a;
	while (i)
	{
	    if(check_if_sorted(stack_a) && get_stack_len(stack_a) == stack_length)
	        break;
		current_min = get_min(stack_a);
		pos = get_min_pos(stack_a, current_min);
		len = get_stack_len(stack_a);
		if(check_if_sorted(stack_a) == 1 && check_if_reverse_sorted(stack_b) == 1)
		{
		    pusher(stack_a, stack_b);
		    break ;
		}
		else if (get_head_val(stack_a) == max && get_last_node_val(stack_a) == min)
			rra(stack_a);
		if(get_second_lowest(stack_a, current_min))
		    sa(stack_a);
	    else if (pos > (len / 2))
			rra_and_pb(stack_a, stack_b, current_min);
		else if (pos <= (len / 2))
			rotate_and_pb(stack_a, stack_b, current_min);
	}
}

struct s_list *parse_args(char *args)
{
	struct s_list *stack;
	char	*arg;
	if(

}

int	main(int argc, char **argv)
{
	int	min;
	int	max;
	size_t	stack_len;
	
	if(argc != 2 || if !argv[1])
	{
		write(2, "Error\n", 6);
		return(0); 
	}
	
	max = get_max(&a);
	min = get_min(&a);
	stack_len = get_stack_len(&a);
	solver(&a, &b, stack_len, min, max);
 	
 	
}
