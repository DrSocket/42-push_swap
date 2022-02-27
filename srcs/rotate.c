/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:48 by lucisanc          #+#    #+#             */
/*   Updated: 2022/01/30 19:44:34 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stck_elem **begin)
{
	if (!*begin)
		return ;
	if ((*begin)->next)
		*begin = (*begin)->next;
}

static void	reverse_rotate(t_stck_elem **begin)
{
	if (!*begin)
		return ;
	if ((*begin)->next)
		*begin = (*begin)->prev;
}

void	move_rotate(t_swap *swap, t_move move)
{
	if (move == move_a)
	{
		rotate(&swap->a->head);
		write(1, "ra\n", 3);
		swap->nbr_move++;
	}
	if (move == move_b)
	{
		rotate(&swap->b->head);
		write(1, "rb\n", 3);
		swap->nbr_move++;
	}
	if (move == move_ab)
	{
		rotate(&swap->a->head);
		rotate(&swap->b->head);
		write(1, "rr\n", 3);
		swap->nbr_move++;
	}
}

void	move_reverse_rotate(t_swap *swap, t_move move)
{
	if (move == move_a)
	{
		reverse_rotate(&swap->a->head);
		write(1, "rra\n", 4);
		swap->nbr_move++;
	}
	if (move == move_b)
	{
		reverse_rotate(&swap->b->head);
		write(1, "rrb\n", 4);
		swap->nbr_move++;
	}
	if (move == move_ab)
	{
		reverse_rotate(&swap->a->head);
		reverse_rotate(&swap->b->head);
		write(1, "rrr\n", 4);
		swap->nbr_move++;
	}
}
