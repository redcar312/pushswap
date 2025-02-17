/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:39:55 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/01/16 15:40:09 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct t_list
{
	int				value;
	size_t			index;
	size_t			cost;
	bool			is_above_median;
	bool			is_cheapest;
	struct t_list	*next;
	struct t_list	*target;
}	t_list;

void				swap(struct t_list **stack);
void				push(struct t_list **dest, struct t_list **src);
void				rotate_stack(struct t_list **stack);
void				reverse_rotate(struct t_list **stack);
void				free_stack(struct t_list **stack);
struct t_list		*get_min(struct t_list *stack);
struct t_list		*get_max(struct t_list *stack);
struct t_list		*find_cheapest(struct t_list **stack);
size_t				get_len(struct t_list **stack);
int					sa(struct t_list **stack_a);
int					pb(struct t_list **stack_a, struct t_list **stack_b);
int					pa(struct t_list **stack_a, struct t_list **stack_b);
int					rrb(struct t_list **stack_a);
int					rra(struct t_list **stack_a);
int					rrr(struct t_list **stack_a, struct t_list **stack_b);
int					rb(struct t_list **stack_a);
int					ra(struct t_list **stack_a);
int					rr(struct t_list **stack_a, struct t_list **stack_b);
int					check_for_dubs(struct t_list **stack, int new_value);
int					zero_case(char *arg);
int					ft_atoi(char const *str);
char				*create_single_arg(char *args);
void				add_node(struct t_list *new_node, struct t_list **stack);
struct t_list		*create_node(char *arg, struct t_list **stack);
size_t				move_index(char *args);
struct t_list		*create_arg_list(char *args, struct t_list *stack);
void				*ft_calloc(size_t nitems, size_t size);
void				add_indexes(struct t_list *stack);
void				set_targets(struct t_list *a, struct t_list *b);
void				set_costs(struct t_list *stack_a, struct t_list *stack_b);
void				set_cheapest(struct t_list *stack_b);
int					check_if_sorted(struct t_list **stack);
int					r_b(struct t_list **a, struct t_list **b, struct t_list *c);
int					r_r(struct t_list **a, struct t_list **b, struct t_list *c);
int					handle_a(struct t_list **a, struct t_list *target);
int					handle_b(struct t_list **a, struct t_list *target);
int					solve_three(struct t_list **stack_a);
void				init_stacks(struct t_list *stack_a, struct t_list *stack_b);
int					mover(struct t_list **a, struct t_list **b);
int					handle_rest(struct t_list **a);
int					handle_five(struct t_list **a, struct t_list **b);
int					solver(struct t_list **a, struct t_list **b);
#endif
