/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:54 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 17:35:45 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a(t_swap *swap, t_stck *a)
{
	t_stck_elem	*current;

	current = a->head;
	while (a->to_push_nbr)
	{
		markup_index(swap->a->stck_size, swap->a->markup_head, true);
		if (current->to_push)
		{
			move_push(swap, move_b);
			current = a->head;
			a->to_push_nbr--;
		}
		else
		{
			move_rotate(swap, move_a);
			current = current->next;
		}
	}
	stack_b(swap, a, swap->b);
}

/*
 *	WHILE stack B is not empty
 *	      choose element in stack B for moving to stack A
 *	      move stack A and stack B to prepare them for pa (push a) \
 *	      with chosen element
 *	      perform pa (push a) command
 *
 */

t_stck_elem	*get_move_elem(t_stck *a, t_stck *b, long *nbr_a, long *nbr_b)
{
	size_t		i;
	long		best_move;
	t_stck_elem	*current;
	t_stck_elem	*elem_to_push;

	i = 0;
	current = b->head;
	best_move = LONG_MAX;
	while (i < b->stck_size)
	{
		(*nbr_b) = get_number_move(b, current);
		(*nbr_a) = get_number_move(a, find_elem(a, current->index));
		if ((ft_abs(*nbr_b) + ft_abs(*nbr_a)) < best_move)
		{
			best_move = ft_abs(*nbr_b) + ft_abs(*nbr_a);
			elem_to_push = current;
		}
		i++;
		current = current->next;
	}
	(*nbr_b) = get_number_move(b, elem_to_push);
	(*nbr_a) = get_number_move(a, find_elem(a, elem_to_push->index));
	return (elem_to_push);
}

void	stack_b(t_swap *swap, t_stck *a, t_stck *b)
{
	long		nbr_a;
	long		nbr_b;

	while (b->stck_size)
	{
		get_move_elem(a, b, &nbr_a, &nbr_b);
		if (nbr_a < 0)
			move_x(&move_reverse_rotate, swap, move_a, nbr_a * -1);
		else
			move_x(&move_rotate, swap, move_a, nbr_a);
		if (nbr_b < 0)
			move_x(&move_reverse_rotate, swap, move_b, nbr_b * -1);
		else
			move_x(&move_rotate, swap, move_b, nbr_b);
		move_push(swap, move_a);
	}
	align_stck(swap, a);
}
