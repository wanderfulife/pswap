/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoWander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:12:55 by JoWander          #+#    #+#             */
/*   Updated: 2024/09/30 17:57:46 by JoWander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_index_in_stack(int *tab, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	int		i;
	long	prev;
	long	curr;

	if (stack->size <= 1)
		return (1);
	i = 0;
	prev = (long)stack->stack[i];
	while (i < stack->size - 1)
	{
		curr = (long)stack->stack[i + 1];
		if (prev < curr)
			return (0);
		prev = curr;
		i++;
	}
	return (1);
}

void	ft_copy_stack(int *dst, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

int	is_sorted_start(t_stack *stack)
{
	int		i;
	long	prev;
	long	curr;

	if (stack->size <= 1)
		return (1);
	i = 0;
	prev = (long)stack->stack[i];
	while (i < stack->size - 1)
	{
		curr = (long)stack->stack[i + 1];
		if (prev > curr)
			return (0);
		prev = curr;
		i++;
	}
	return (1);
}
