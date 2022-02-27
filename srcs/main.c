/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:22 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/27 10:07:16 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stck_elem *lst)
{
	t_stck_elem	*tmp;

	if (lst && lst->prev)
	{
		tmp = lst->prev;
		tmp->next = NULL;
	}
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	write(1, "Error\n", 7);
	exit(1);
}

void	init(t_swap *swap, t_stck *a, t_stck *b)
{
	*swap = (t_swap){NULL, 0, a, b, 0};
	*a = (t_stck){0, 0, NULL, NULL, 0, 0, 0, 0};
	*b = (t_stck){0, 0, NULL, NULL, 0, 0, 0, 0};
}

void	stack_help(t_swap *swap)
{
	get_best_markup_head(swap, swap->a->head, &markup_index);
	stack_a(swap, swap->a, &markup_index);
}

void	main_help(t_swap *swap)
{
	lst_join_begin_last(swap->a->head);
	swap->array = init_quicksort(swap->a->head, \
			swap->a->stck_size, &swap->size_array);
	lst_index(swap->a->head, swap->a->stck_size, \
			swap->array, swap->size_array);
}

int	main(int ac, char **av)
{
	t_swap	swap;
	t_stck	a;
	t_stck	b;

	init(&swap, &a, &b);
	parsing(&swap, ac, av);
	if (ac == 1 || swap.a->stck_size <= 1)
	{	
		destroy_lst(&swap.a->head);
		return (0);
	}
	main_help(&swap);
	if (swap.a->stck_size <= 3)
		sort_three(&swap, swap.a->head);
	else if (swap.a->stck_size <= 5)
		sort_five(&swap, swap.a, swap.b);
	else
		stack_help(&swap);
	// insertion_sort(&swap);
	destroy_lst(&swap.a->head);
	destroy_lst(&swap.b->head);
	free(swap.array);
}
