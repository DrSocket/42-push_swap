#include "push_swap.h"

void	set_n(t_swap *swap)
{
	size_t		i;
	size_t		j;
	size_t		temp;
	t_stck_elem		*head;

	temp = 0;
	head = swap->a->head;
	i = swap->a->n_one;
	j = swap->a->n_two;
	while (temp < swap->a->stck_size)
	{
		if (head->index == i)
			swap->a->depth_one = temp;
		if (head->index == j)
			swap->a->depth_two = temp;
		head = head->next;
		temp++;
	}
}

int		in_chunk(size_t index, size_t size, size_t min, size_t max)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	while (i++ < size)
		if (index >= min && index <= max)
			x = 1;
	return (x);
}

void	sort_100(t_swap *swap, size_t min, size_t max)
{
	long			i;
	long			size;
	t_stck_elem		*head;
	size_t		t_1 = swap->a->n_one;
	size_t		t_2 = swap->a->n_two;

	i = 0;
	head = swap->a->head;
	size = swap->a->stck_size;
	while (i++ < size)
	{
		if (in_chunk(head->index, size, min, max))
		{
	// printf("depth_one = [%zu] \n", swap->a->depth_one);

			t_1 = head->index;
			swap->a->depth_one = i;
			break;
		}
		head = head->next;
	}
	i = 0;
	while (size - i++ > 0 )
	{
		if (i < swap->a->depth_one && in_chunk(head->index, size, min, max))
		{
			t_1 = head->index;
			swap->a->depth_one = size - i;
			break;
		}
		head = head->prev;
	}
	i = 0;
	while (i++ < size)
	{
		if (in_chunk(head->index, size, min, max))
		{
	// printf("depth_two = [%zu] \n", swap->a->depth_two);
			t_2 = head->index;
			swap->a->depth_two = i;
			break;
		}
		head = head->next;
	}
	i = 0;
	while (size - i++ > 0)
	{
		if (i < swap->a->depth_two && in_chunk(head->index, size, min, max))
		{
			t_2 = head->index;
			swap->a->depth_two = size - i;
			break;
		}
		head = head->prev;
	}
	// printf("t_1 = [%zu] t_2 = [%zu] | depth_one = [%zu] depth_two = [%zu]\n", t_1, t_2, swap->a->depth_one, swap->a->depth_two);
}

void	prepare_push(t_swap *swap)
{
	size_t		abs_one;
	size_t		abs_two;
	size_t		size = swap->a->stck_size;

	abs_one = ft_abs(swap->a->depth_one);
	abs_two = ft_abs(swap->a->depth_two);
	if (abs_one <= abs_two)
	{
		if (abs_one <= (size/2))
			while (--abs_one > 0)
				move_rotate(swap, move_a);
		else
			while (abs_one-- > 0)
				move_reverse_rotate(swap, move_a);
	}
	else
	{
		if (abs_two <= (size/2))
			while (--abs_two > 0)
				move_rotate(swap, move_a);
		else
			while (abs_two-- > 0)
				move_reverse_rotate(swap, move_a);
	}
}

size_t	ft_max(t_stck_elem *p_head, size_t size, size_t *i)
{
	size_t	x;
	size_t	max;

	max = p_head->index;
	while ( (*i)++ < size )
	{
		if (max < p_head->index)
		{
			max = p_head->index;
			x = (*i);
		}
		p_head = p_head->next;
	}
	*i = x;
	return (max);
}

size_t	ft_min(t_stck_elem *p_head, size_t size, size_t *i)
{
	size_t	x;
	size_t	min;

	min = p_head->index;
	while ( (*i)++ < size )
	{
		if (min > p_head->index)
		{
			min = p_head->index;
			x = (*i);
		}
		p_head = p_head->next;
	}
	*i = x;
	return (min);
}

size_t	ft_next(t_swap *swap, size_t *depth)
{
	size_t	index = swap->a->head->index;
	size_t	ret = 0;
	size_t	temp = 0;
	size_t	i = 0;

	while (i < swap->b->stck_size)
	{
		if (swap->b->head->index > index)
			;
		else if (swap->b->head->index > temp)
		{
			ret = swap->b->head->index;
			temp = swap->b->head->index;
			(*depth) = i;
		}
		swap->b->head = swap->b->head->next;
		i++;
	}
	return (ret);
}

void	align_b(t_swap *swap)
{
	size_t	max;
	size_t	next;
	size_t	min;
	size_t	depth;
	size_t	max_depth;
	size_t	min_depth;

	depth = 0;
	max_depth = 0;
	min_depth = 0;
	max = ft_max(swap->b->head, swap->b->stck_size, &max_depth);
	min = ft_min(swap->b->head, swap->b->stck_size, &min_depth);
	next = ft_next(swap, &depth);
	// printf("max [%zu] min [%zu]\tmax_depth [%zu] min_depth [%zu]\tsize [%zu]\n", max, min, max_depth, min_depth, swap->b->stck_size);
	if (swap->a->head->index > max)
	{
		if (max_depth <= (swap->b->stck_size/2 + 1))
			while (swap->b->head->index != max)
				move_rotate(swap, move_b);
		else
			while (swap->b->head->index != max)
				move_reverse_rotate(swap, move_b);
	}
	else if (swap->a->head->index < min)
	{
		if (min_depth <= (swap->b->stck_size/2 + 1))
			while (swap->b->head->index != max)
				move_rotate(swap, move_b);
		else
			while (swap->b->head->index != max)
				move_reverse_rotate(swap, move_b);
	}
	else
	{
		if (depth <= (swap->b->stck_size/2 + 1))
			while (swap->b->head->index != next)
				move_rotate(swap, move_b);
		else
			while (swap->b->head->index != next)
				move_reverse_rotate(swap, move_b);
	}
}

void	push_back(t_swap *swap)
{
	size_t depth = 0;
	size_t size = swap->b->stck_size;
	size_t max = ft_max(swap->b->head, size, &depth);

	if (depth < (size/2))
		while (swap->b->head->index != max)
			move_rotate(swap, move_b);
	else
		while (swap->b->head->index != max)
			move_reverse_rotate(swap, move_b);
}

void	keep_nb(t_swap *swap)
{
	t_swap *x = swap;
	if (x < swap)
		;
}

void	insertion_sort(t_swap *swap)
{
	size_t	min = 0;
	size_t max = 20;
	size_t i = 0;
	size_t original_sz = swap->a->stck_size;

	swap->a->n_one = max-1;
	swap->a->n_two = max;
	if (max > swap->a->stck_size)
		max = original_sz;
	while (swap->a->stck_size > 1)
	{	
		if (++i % 20 == 0)
		{
			min += 20;
			if (max + min > original_sz - 1)
				max = original_sz;
			else
				max += min;
		}
		// printf("min = [%zu] max [%zu]\n", min, max);
		keep_nb(swap);
		sort_100(swap, min, max);
		// depth(swap);
		prepare_push(swap);
		if (swap->b->stck_size > 1)
			align_b(swap);
		move_push(swap, move_b);
		swap->a->n_one = max-1;
		swap->a->n_two = max;
		// print_stack(swap);
	}
	// align_b(swap);
	move_push(swap, move_b);
	// print_stack(swap);
	while (swap->b->stck_size >= 1)
	{
		push_back(swap);
		move_push(swap, move_a);
	}
	// print_stack(swap);
}