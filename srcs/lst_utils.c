/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:17 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 16:23:09 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stck_elem	*lst_new_node(long int nb)
{
	t_stck_elem	*new;

	new = malloc(sizeof(t_stck_elem));
	if (!new)
		return (0);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	lst_join_begin_last(t_stck_elem *first)
{
	t_stck_elem	*last;

	last = lst_get_last(first);
	first->prev = last;
	last->next = first;
}

t_stck_elem	*lst_get_last(t_stck_elem *stck)
{
	while (stck->next)
		stck = stck->next;
	return (stck);
}

void	lst_create_head(t_stck_elem **begin, long int nb)
{
	(*begin) = lst_new_node(nb);
	if (!*begin)
		error_exit(*begin);
	(*begin)->prev = NULL;
}

void	lst_add_to_stack(t_stck_elem **begin, size_t *size_stck, long int nb)
{
	t_stck_elem	*lst;
	t_stck_elem	*new;

	if (!*begin)
	{
		lst_create_head(begin, nb);
		(*size_stck)++;
		return ;
	}
	lst = lst_get_last(*begin);
	new = lst_new_node(nb);
	if (!new)
		error_exit(*begin);
	lst->next = new;
	new->prev = lst;
	(*size_stck)++;
}
