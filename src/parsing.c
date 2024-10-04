/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoWander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:03:46 by JoWander          #+#    #+#             */
/*   Updated: 2024/10/04 10:26:16 by JoWander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	already_exists(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	add_number_in_stack(t_stack *stack, char *str)
{
	long	num;

	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (stack->size == stack->max_size)
		return (0);
	if (already_exists(stack, (int)num))
		return (0);
	stack->stack[stack->size] = (int)num;
	stack->size++;
	return (1);
}

int	parse_single_argument(t_push_swap *ps, char *str)
{
	char	**split;
	int		i;
	int		success;

	split = ft_split(str, ' ');
	success = 1;
	if (!split)
		return (0);
	i = 0;
	while (split[i] && success)
	{
		if ((!is_valid(split[i]) || !add_number_in_stack(ps->a, split[i])))
			success = 0;
		i++;
	}
	ft_free_split(split);
	return (success);
}

int	parse_multiple_arguments(t_push_swap *ps, int nb_args, char **av)
{
	int	i;

	i = 1;
	while (i < nb_args)
	{
		if (!is_valid(av[i]) || !add_number_in_stack(ps->a, av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(t_push_swap *ps, int ac, char **av)
{
	if (ac == 2)
		return (parse_single_argument(ps, av[1]));
	return (parse_multiple_arguments(ps, ac, av));
}
