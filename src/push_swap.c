/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JWander <jowander@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:11make:25 by JoWander          #+#    #+#             */
/*   Updated: 2024/10/01 10:49:40 by JWander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

static int	is_valid_input(int ac, char **av)
{
	char	**split;
	int		j;

	while (--ac > 0)
	{
		split = ft_split(av[ac], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!is_valid(split[j]))
			{
				ft_free_split(split);
				return (0);
			}
			j++;
		}
		ft_free_split(split);
	}
	return (1);
}

static t_push_swap	*init_all(int ac, char **av)
{
	int			total_numbers;
	t_push_swap	*ps;

	total_numbers = count_total_numbers(ac, av);
	if (total_numbers <= 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (NULL);
	}
	ps = init_push_swap(total_numbers);
	if (!ps)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (NULL);
	}
	return (ps);
}

static int	has_duplicates(t_push_swap *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->a->size - 1)
	{
		j = i + 1;
		while (j < ps->a->size)
		{
			if (ps->a->stack[i] == ps->a->stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	handle_duplicates_and_sort(t_push_swap *ps)
{
	if (has_duplicates(ps))
	{
		ft_putstr_fd("Error: Duplicate numbers found\n", 2);
		return (ft_cleanup_and_print_error(ps), 1);
	}
	if (!is_sorted_start(ps->a))
	{
		if (ps->a->size <= 5)
			sort_small_set(ps);
		else
		{
			simplify_stack(ps);
			radix_sort(ps);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac < 2)
		return (0);
	if (!is_valid_input(ac, av))
		return (ft_putendl_fd("Error", ERROR_EXIT), 1);
	ps = init_all(ac, av);
	if (!ps || !parse_arguments(ps, ac, av))
		return (ft_cleanup_and_print_error(ps), 1);
	if (handle_duplicates_and_sort(ps))
		return (1);
	free_push_swap(ps);
	return (0);
}
