/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:55:04 by lucisanc          #+#    #+#             */
/*   Updated: 2022/01/30 19:44:34 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fswap(t_stck_elem **top)
{
	t_stck_elem	*new_top;
	t_stck_elem	*head;

	head = (*top);
	new_top = head->next;
	head->prev->next = new_top;
	new_top->next->prev = head;
	new_top->prev = head->prev;
	head->prev = new_top;
	head->next = new_top->next;
	new_top->next = head;
	(*top) = new_top;
}

void	move_swap(t_swap *swap, t_move move)
{
	swap->nbr_move++;
	if (move == move_a)
	{
		if (!(swap->a->stck_size > 1))
			return ;
		fswap(&swap->a->head);
		write(1, "sa\n", 3);
	}
	else if (move == move_b)
	{
		if (!(swap->b->stck_size > 1))
			return ;
		fswap(&swap->b->head);
		write(1, "sb\n", 3);
	}
	else if (move == move_ab)
	{
		if (!(swap->a->stck_size > 1))
			return ;
		if (!(swap->b->stck_size > 1))
			return ;
		fswap(&swap->a->head);
		fswap(&swap->b->head);
		write(1, "ss\n", 3);
	}
}
