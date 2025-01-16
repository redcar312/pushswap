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

size_t	get_len(int *arr)
{
	size_t	i;
	
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	get_max_num(int *arr)
{
	int	max;
	size_t	i;

	i = 0;
	max = arr[0];
	while (arr[i])
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max)
}

void	sort_arr(int *a, int *b)
{


		
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
	bhead = newhead->next;
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
		if(current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	sort_stacks(struct s_list **a, struct s_list **b)
{
	
	
}

int	main()
{
	int a[] = {5, 0, 9, 1, 95};
	int b[5];
	int	min;
	int	max;
		
	max = get_max(a);
	min = get_min(a);
	sort(a, b, min, max);		
}
