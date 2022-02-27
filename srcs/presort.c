/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:33 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 16:45:15 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_quicksort *qs, int num1, int num2)
{
	int	tmp;

	tmp = num1[qs->array];
	num1[qs->array] = num2[qs->array];
	num2[qs->array] = tmp;
}

static int	partition(t_quicksort *qs, int left, int right, int pivot)
{
	int	left_p;
	int	right_p;

	left_p = left - 1;
	right_p = right;
	while (1)
	{
		while (qs->array[++left_p] < pivot)
			;
		while (right_p > 0 && qs->array[--right_p] > pivot)
			;
		if (left_p >= right_p)
			break ;
		else
			swap(qs, left_p, right_p);
	}
	swap(qs, left_p, right);
	return (left_p);
}

static void	fn_qs(t_quicksort *qs, int left, int right)
{
	int	pivot;

	if (right - left <= 0)
		return ;
	else
	{
		pivot = qs->array[right];
		qs->partition = partition(qs, left, right, pivot);
		if (right - left <= 0)
			return ;
		fn_qs(qs, left, qs->partition - 1);
		fn_qs(qs, qs->partition + 1, right);
	}
}

void	print_array(int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(i[array], 1);
		write(1, "|", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	*init_quicksort(t_stck_elem *lst, size_t size_lst, size_t *size_array)
{
	t_quicksort	qs;
	size_t		i;

	qs.array = malloc(sizeof(int) * size_lst);
	if (!(qs.array))
		return (0);
	i = 0;
	while (i < size_lst)
	{
		qs.array[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	qs.size = size_lst - 1;
	fn_qs(&qs, 0, qs.size);
	*size_array = size_lst;
	return (qs.array);
}
