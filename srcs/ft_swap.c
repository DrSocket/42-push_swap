#include "push_swap.h"

int		ft_swap(int *tab)
{
	int n;

	n = tab[0];
	tab[0] = tab[1];
	tab[1] = n;
	return (1);
}

int		ft_swap_a(t_struct *stack)
{
	if (stack->a.size > 1)
		ft_swap(stack->a.tab);
	return (1);
}

int		ft_swap_b(t_struct *stack)
{
	if (stack->b.size > 1)
		ft_swap(stack->b.tab);
	return (1);
}

int		ft_swapboth(t_struct *stack)
{
	ft_swap_a(stack);
	ft_swap_b(stack);
	return (1);
}