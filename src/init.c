/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoWander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:43:50 by JoWander          #+#    #+#             */
/*   Updated: 2024/09/30 17:57:58 by JoWander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

t_stack	*init_stack(int max_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->stack = malloc(sizeof(int) * max_size);
	if (!stack->stack)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->max_size = max_size;
	return (stack);
}

t_push_swap	*init_push_swap(int max_size)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
	ps->a = init_stack(max_size);
	ps->b = init_stack(max_size);
	if (!ps->a || !ps->b)
	{
		free_push_swap(ps);
		return (NULL);
	}
	return (ps);
}
