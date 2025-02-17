/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:29:46 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/02/16 15:30:37 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_dubs(struct t_list **stack, int new_value)
{
	struct t_list	*current;

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

static int	checker(char *str)
{
	size_t	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	calc_sum(char *str, int is_neg)
{
	size_t		i;
	long long	sum;

	i = 0;
	sum = 0;
	if (!checker(str))
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (i > 0)
			sum *= 10;
		sum += (str[i] - 48);
		i++;
	}
	if (is_neg)
		sum *= -1;
	if (sum > INT_MAX || sum < INT_MIN)
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
