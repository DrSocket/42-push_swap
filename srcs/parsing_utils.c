/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:29 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/11 18:30:28 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_nb_repeat(t_stck_elem *lst, long int nb, size_t size)
{
	if (!lst)
		return ;
	while (size--)
	{
		if (lst->nb == nb)
			error_exit(lst);
		lst = lst->next;
	}
}

void	check_valid_input(t_swap *swap, char *str, int tmp)
{
	if (tmp < 0)
		error_exit(swap->a->head);
	while (str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str)
		error_exit(swap->a->head);
}

int	ft_atoi_err(long int *nb, char **av)
{
	int	sign;
	int	ret;

	*nb = 0;
	ret = 0;
	sign = 1;
	while ((**av >= 9 && **av <= 13) || **av == ' ')
		(*av)++;
	if (**av == '-' || **av == '+')
	{
		if (**av == '-')
			sign *= -1;
		(*av)++;
	}
	while (**av >= '0' && **av <= '9')
	{
		ret = 1;
		*nb *= 10;
		*nb += (**av - '0') * sign;
		if (*nb > INT_MAX || *nb < INT_MIN)
			return (-1);
		(*av)++;
	}
	return (ret);
}

void	parsing(t_swap *swap, int ac, char **av)
{
	int			ret_atoi;
	char		*tmp;
	int			i;
	long		nb;

	i = 0;
	while (++i < ac)
	{
		while (*av[i] != '\0')
		{
			tmp = av[i];
			ret_atoi = ft_atoi_err(&nb, &av[i]);
			if (ret_atoi <= 0)
				check_valid_input(swap, tmp, ret_atoi);
			else
			{
				check_nb_repeat(swap->a->head, nb, swap->a->stck_size);
				lst_add_to_stack(&swap->a->head, &swap->a->stck_size, nb);
			}
		}
	}
}
