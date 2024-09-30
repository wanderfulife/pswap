/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoWander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:07:27 by JoWander          #+#    #+#             */
/*   Updated: 2024/09/30 17:58:05 by JoWander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/includes/libft.h"

void	simplify_stack(t_push_swap *ps)
{
	int		i;
	int		j;
	int		rank;
	int		*copy;

	copy = malloc(sizeof(int) * ps->a->size);
	if (!copy)
		ft_cleanup_and_print_error(ps);
	i = -1;
	while (++i < ps->a->size)
		copy[i] = ps->a->stack[i];
	i = -1;
	while (++i < ps->a->size)
	{
		rank = 0;
		j = -1;
		while (++j < ps->a->size)
			if (copy[j] < copy[i] || (j < i && copy[j] == copy[i]))
				rank++;
		ps->a->stack[i] = rank;
	}
	free(copy);
}

int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_push_swap *ps)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_num = ps->a->size - 1;
	max_bits = get_max_bits(max_num);
	size = ps->a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((ps->a->stack[0] >> i) & 1) == 1)
				ft_ra(ps);
			else
				ft_pb(ps);
			j++;
		}
		while (ps->b->size != 0)
			ft_pa(ps);
		i++;
	}
}
