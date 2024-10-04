// src/movements/reverse_rotate.c 
void	ft_rra(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[ps->a->size - 1];
	i = ps->a->size - 1;
	while (i > 0)
	{
		ps->a->stack[i] = ps->a->stack[i - 1];
		i--;
	}
	ps->a->stack[0] = tmp;
	ft_printf("rra\n");
}
void	ft_rrb(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[ps->b->size - 1];
	i = ps->b->size - 1;
	while (i > 0)
	{
		ps->b->stack[i] = ps->b->stack[i - 1];
		i--;
	}
	ps->b->stack[0] = tmp;
	ft_printf("rrb\n");
}
void	ft_rrr(t_push_swap *ps)
{
	ft_rra(ps);
	ft_rrb(ps);
	ft_printf("rrr\n");
}
// src/movements/rotate.c 
void	ft_ra(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->stack[0];
	i = 0;
	while (i < ps->a->size - 1)
	{
		ps->a->stack[i] = ps->a->stack[i + 1];
		i++;
	}
	ps->a->stack[ps->a->size - 1] = tmp;
	ft_printf("ra\n");
}
void	ft_rb(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->stack[0];
	i = 0;
	while (i < ps->b->size - 1)
	{
		ps->b->stack[i] = ps->b->stack[i + 1];
		i++;
	}
	ps->b->stack[ps->b->size - 1] = tmp;
	ft_printf("rb\n");
}
void	ft_rr(t_push_swap *ps)
{
	ft_ra(ps);
	ft_rb(ps);
	ft_printf("rr\n");
}
// src/movements/swap_push.c
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
// src/sort/radix_sort.c
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
// src/sort/small_sort.c
void	sort_two(t_push_swap *ps)
{
	if (ps->a->stack[0] > ps->a->stack[1])
		ft_sa(ps);
}
void	sort_three(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->stack[0];
	b = ps->a->stack[1];
	c = ps->a->stack[2];
	if (a > b && b < c && a < c)
		ft_sa(ps);
	else if (a > b && b > c)
	{
		ft_sa(ps);
		ft_rra(ps);
	}
	else if (a > b && b < c && a > c)
		ft_ra(ps);
	else if (a < b && b > c && a < c)
	{
		ft_sa(ps);
		ft_ra(ps);
	}
	else if (a < b && b > c && a > c)
		ft_rra(ps);
}
void	sort_four_five(t_push_swap *ps)
{
	int	min_index;

	while (ps->a->size > 3)
	{
		min_index = find_min_value_return_index(ps->a);
		while (min_index > 0)
		{
			if (min_index <= ps->a->size / 2)
				ft_ra(ps);
			else
				ft_rra(ps);
			min_index = find_min_value_return_index(ps->a);
		}
		ft_pb(ps);
	}
	sort_three(ps);
	while (ps->b->size > 0)
		ft_pa(ps);
}
void	sort_small_set(t_push_swap *ps)
{
	if (ps->a->size == 2)
		sort_two(ps);
	else if (ps->a->size == 3)
		sort_three(ps);
	else if (ps->a->size <= 5)
		sort_four_five(ps);
}
// src/cleanup.c 
void	free_push_swap(t_push_swap *ps)
{
	if (ps)
	{
		if (ps->a)
		{
			free(ps->a->stack);
			free(ps->a);
		}
		if (ps->b)
		{
			free(ps->b->stack);
			free(ps->b);
		}
		free(ps);
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
//scr/init.c
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
//src/parsing.c
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
// src/push_swap.c
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
// src/utils.c
void	ft_cleanup_and_print_error(t_push_swap *ps)
{
	ft_putendl_fd(ERROR_MESSAGE, ERROR_EXIT);
	if (ps)
		free_push_swap(ps);
	exit(1);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_total_numbers(int ac, char **av)
{
	int		total_numbers;
	char	**split;
	int		i;
	int		j;

	total_numbers = 0;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			if (is_valid(split[j]))
				total_numbers++;
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (total_numbers);
}

int	find_max(t_stack *a)
{
	int	max;
	int	i;

	max = a->stack[0];
	i = 1;
	while (i < a->size)
	{
		if (a->stack[i] > max)
			max = a->stack[i];
		i++;
	}
	return (max);
}

int	find_min_value_return_index(t_stack *stack)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] < stack->stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
// src/utils2.c
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

