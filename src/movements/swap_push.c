/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JoWander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:57:09 by JoWander          #+#    #+#             */
/*   Updated: 2024/09/30 17:58:14 by JoWander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	ft_sa(t_push_swap *ps)
{
	int	tmp;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[0];
	ps->a->stack[0] = ps->a->stack[1];
	ps->a->stack[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_push_swap *ps)
{
	int	tmp;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[0];
	ps->b->stack[0] = ps->b->stack[1];
	ps->b->stack[1] = tmp;
	ft_printf("sb\n");
}

void	ft_ss(t_push_swap *ps)
{
	ft_sa(ps);
	ft_sb(ps);
	ft_printf("ss\n");
}

void	ft_pa(t_push_swap *ps)
{
	int	i;

	if (ps->b->size == 0)
		return ;
	i = ps->a->size;
	while (i > 0)
	{
		ps->a->stack[i] = ps->a->stack[i - 1];
		i--;
	}
	ps->a->stack[0] = ps->b->stack[0];
	i = 0;
	while (i < ps->b->size - 1)
	{
		ps->b->stack[i] = ps->b->stack[i + 1];
		i++;
	}
	ps->a->size++;
	ps->b->size--;
	ft_printf("pa\n");
}

void	ft_pb(t_push_swap *ps)
{
	int	i;

	if (ps->a->size == 0)
		return ;
	i = ps->b->size;
	while (i > 0)
	{
		ps->b->stack[i] = ps->b->stack[i - 1];
		i--;
	}
	ps->b->stack[0] = ps->a->stack[0];
	i = 0;
	while (i < ps->a->size - 1)
	{
		ps->a->stack[i] = ps->a->stack[i + 1];
		i++;
	}
	ps->b->size++;
	ps->a->size--;
	ft_printf("pb\n");
}
