/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:55:01 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 17:36:31 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_number_move(t_stck *stck, t_stck_elem *elem)
{
	long int	i;
	t_stck_elem	*current;

	i = 0;
	current = stck->head;
	while (current != elem && stck->stck_size > (size_t)i)
	{
		i++;
		current = current->next;
	}
	if (!i || i == 1)
		return (i);
	if (i > ((long long int)stck->stck_size >> 1))
		i -= (long long int)stck->stck_size;
	return (i);
}

t_stck_elem	*find_elem(t_stck *stck, size_t index)
{
	t_stck_elem	*current;

	current = stck->head;
	if (index < current->index)
	{
		while (index < current->prev->index && \
				current->index > current->prev->index)
			current = current->prev;
	}
	else
	{
		while (index > current->index && current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
}
