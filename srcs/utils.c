/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:55:07 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/26 16:19:03 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_lst(t_stck_elem **elem)
{
	t_stck_elem	*tmp;

	if (!elem || !(*elem))
		return ;
	if ((*elem)->prev)
		(*elem)->prev->next = NULL;
	while (*elem)
	{
		tmp = (*elem)->next;
		free(*elem);
		*elem = tmp;
	}
	*elem = NULL;
}

long int	ft_abs(long int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		nb_w;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", fd);
		nb *= -1;
	}
	nb_w = nb + '0';
	if (nb < 10)
		write(1, &nb_w, 1);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

int	is_sorted(t_swap *swap)
{
	size_t		i;
	t_stck_elem	*current;

	i = 0;
	current = swap->a->head;
	if (swap->b->stck_size != 0)
		return (0);
	while (i < swap->a->stck_size)
	{
		if (current->nb > current->next->nb)
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

void	move_x(void (*move)(t_swap *, t_move),
		t_swap *swap, t_move mv, long nbr)
{
	while (nbr-- > 0)
		move(swap, mv);
}
