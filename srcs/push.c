/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:37 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 17:44:19 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stck_elem	*lst_remove_top(
		t_stck_elem **src,
		size_t *size_src)
{
	t_stck_elem	*ret;

	if (!*size_src)
		return (NULL);
	ret = (*src);
	if (*size_src != 1)
	{
		ret->prev->next = ret->next;
		ret->next->prev = ret->prev;
	}
	*src = ret->next;
	(*size_src)--;
	if (*size_src == 1)
	{
		(*src)->prev = NULL;
		(*src)->next = NULL;
	}
	return (ret);
}

static void	lst_add_top(
		t_stck_elem **dest,
		size_t *size_dest,
		t_stck_elem *new)
{
	t_stck_elem	*last;

	if (!*size_dest)
	{
		*dest = new;
		new->next = new;
		new->prev = new;
		(*size_dest)++;
		return ;
	}
	last = (*dest);
	if (*size_dest != 1)
		last = (*dest)->prev;
	new->next = (*dest);
	new->prev = last;
	last->next = new;
	(*dest)->prev = new;
	(*dest) = new;
	(*size_dest)++;
}

static void	push(
		t_stck_elem **src,
		size_t *size_src,
		t_stck_elem **dest,
		size_t *size_dest)
{
	t_stck_elem	*tmp;

	tmp = lst_remove_top(src, size_src);
	lst_add_top(dest, size_dest, tmp);
}

void	move_push(t_swap *swap,
		t_move move)
{
	if (move == move_a)
	{
		if (!swap->b->stck_size)
			return ;
		push(&swap->b->head, &swap->b->stck_size, \
				&swap->a->head, &swap->a->stck_size);
		write(1, "pa\n", 3);
		swap->nbr_move++;
	}
	if (move == move_b)
	{
		if (!swap->a->stck_size)
			return ;
		push(&swap->a->head, &swap->a->stck_size, \
				&swap->b->head, &swap->b->stck_size);
		write(1, "pb\n", 3);
		swap->nbr_move++;
	}
	if (!swap->a->stck_size)
		swap->a->head = NULL;
	if (!swap->b->stck_size)
		swap->b->head = NULL;
}
