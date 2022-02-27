/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_stcks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:23:56 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/27 09:56:09 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_swap *swap)
{
	size_t		i;
	size_t		size;
	t_stck_elem	*tmp;

	size = swap->a->stck_size;
	tmp = swap->a->head;
	i = 0;
	if (size != 1)
	{
		printf("debug : swap.a [%p]\n\tswap.b [%p]\n\t[a]||", \
		swap->a, swap->b);
		while (i++ < size)
		{
			printf("[%02li]", tmp->nb);
			tmp = tmp->next;
		}
	}
	size = swap->b->stck_size;
	if (size != 1)
	{
		tmp = swap->b->head;
		i = 0;
		printf("\n\t[b]||");
		while (i++ < size)
		{
			printf("[%02li]", tmp->nb);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
