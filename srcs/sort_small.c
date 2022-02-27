/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:58 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 17:42:58 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_swap *swap, t_stck_elem *a)
{
	long	sec;
	long	lst;

	sec = a->next->nb;
	lst = a->prev->nb;
	if (swap->a->stck_size == 2 && a->nb > sec)
		move_rotate(swap, move_a);
	else if (a->nb < sec && sec > lst && a->nb < lst)
	{
		move_swap(swap, move_a);
		move_rotate(swap, move_a);
	}
	else if (a->nb > sec && sec < lst && a->nb < lst)
		move_swap(swap, move_a);
	else if (a->nb < sec && sec > lst && a->nb > lst)
		move_reverse_rotate(swap, move_a);
	else if (a->nb > sec && sec < lst && a->nb > lst)
		move_rotate(swap, move_a);
	else if (a->nb > sec && sec > lst && a->nb > lst)
	{
		move_swap(swap, move_a);
		move_reverse_rotate(swap, move_a);
	}
}

void	insert(t_swap *swap, t_stck *a, t_stck *b)
{
	long	nbr_a;

	while (b->stck_size)
	{
		nbr_a = get_number_move(a, find_elem(a, b->head->index));
		if (nbr_a < 0)
			move_x(&move_reverse_rotate, swap, move_a, nbr_a * -1);
		else if (nbr_a > 0)
			move_x(&move_rotate, swap, move_a, nbr_a);
		move_push(swap, move_a);
	}
}

void	align_stck(t_swap *swap, t_stck *stck)
{
	int			counter;
	t_stck_elem	*current;

	counter = 0;
	current = stck->head;
	printf("%ld\n", current->nb);
	while (current->index != 0)
	{
		counter++;
		current = current->next;
	}
	if (!counter)
		return ;
	if (counter > (int)((stck->stck_size / 2)))
	{
		while (counter++ != (int)stck->stck_size)
			move_reverse_rotate(swap, move_a);
	}
	else
	{
		while (counter--)
			move_rotate(swap, move_a);
	}
}

void	sort_five(t_swap *swap, t_stck *a, t_stck *b)
{
	move_push(swap, move_b);
	move_push(swap, move_b);
	sort_three(swap, swap->a->head);
	insert(swap, a, b);
	align_stck(swap, a);
}
