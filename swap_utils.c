/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:33:14 by mhurtamo          #+#    #+#             */
/*   Updated: 2025/01/08 18:21:25 by mhurtamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_one(int *arr)
{
	int	temp;

	if (!arr)
		return ;

	if (arr[0] && arr[1])
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;	
	}
}

void	swap_both(int *a, int *b)
{
	swap_one(a);
	swap_one(b);
}

void	push_arr(int *arr1, int *arr2)
{
	int	temp;
	int	t2;
	size_t	i;

	i = 0;
	if (!arr2)
		return ;
	t2 = arr2[0];
	while (arr1[i])
	{
		temp = arr1[i];
		arr1[i] = t2;
		t2 = temp;
		i++;	
	}
	arr1[i] = t2;
}

void	rotate_one(int *arr)
{
	size_t	i;
	int	temp;
	if (!arr)
		return ;
	temp = arr[0];
	i = 1;
	while (arr[i])
	{
		arr[i - 1] = arr[i];
		i++;	
	}
	arr[i] = temp;
}

void rotate_both(int *a, int *b)
{
	rotate_one(a);
	rotate_one(b);
}

void	rr_one(int *arr)
{
	int	temp;
	int	t2;
	size_t	i;
	
	if (!arr)
		return ;
	i = 0;
	temp = arr[0]
	while (arr[i])
	{
	
		t2 = arr[i];	
		arr[i] = temp;
		temp = t2;
				
	}
	arr[0] = arr[i];
}
