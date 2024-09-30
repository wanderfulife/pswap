/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoWander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:10:25 by JoWander          #+#    #+#             */
/*   Updated: 2024/09/30 17:57:52 by JoWander         ###   ########.fr       */
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

static int has_duplicates(t_push_swap *ps)
{
	int i, j;
	for (i = 0; i < ps->a->size - 1; i++)
	{
		for (j = i + 1; j < ps->a->size; j++)
		{
			if (ps->a->stack[i] == ps->a->stack[j])
				return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;

	if (ac < 2)
		return (0);  // Exit if no arguments provided (program name is always the first argument)

	if (!is_valid_input(ac, av))
	{
		ft_putendl_fd("Error", STDERR_FILENO);  // Print error message to stderr if input is invalid
		return (1);  // Return 1 to indicate an error occurred
	}

	ps = init_all(ac, av);  // Initialize the push_swap structure with the given arguments
	if (!ps || !parse_arguments(ps, ac, av))
	{
		if (has_duplicates(ps))
		{
			ft_putstr_fd("Error: Duplicate numbers found\n", 2);
			return (ft_cleanup_and_print_error(ps), 1);
		}
		return (ft_cleanup_and_print_error(ps), 1);  // Clean up memory, print error, and exit if initialization or parsing fails
	}

	if (!is_sorted_start(ps->a))  // Check if the initial stack 'a' is already sorted
	{
		if (ps->a->size <= 5)
		{
			sort_small_set(ps);  // Use a specific algorithm for sorting small sets (5 or fewer elements)
		}
		else
		{
			simplify_stack(ps);  // Convert the stack values to a simplified form (e.g., ranking)
			radix_sort(ps);  // Use radix sort algorithm for larger sets of numbers
		}
	}

	free_push_swap(ps);  // Free all allocated memory in the push_swap structure
	return (0);  // Return 0 to indicate successful execution
}
