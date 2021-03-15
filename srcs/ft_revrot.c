#include "push_swap.h"

int		ft_rra(int *tab, int size)
{
	int tmp;

	size--;
	tmp = tab[size];
	while (size)
	{
		tab[size] = tab[size - 1];
		tab[size - 1] = tmp;
		size--;
	}
	return (1);
}

int		ft_rra_a(t_struct *stack)
{
	ft_rra(stack->a.tab, stack->a.size);
	return (1);
}

int		ft_rra_b(t_struct *stack)
{
	ft_rra(stack->b.tab, stack->b.size);
	return (1);
}

int		ft_rrboth(t_struct *stack)
{
	ft_rra(stack->a.tab, stack->a.size);
	ft_rra(stack->b.tab, stack->b.size);
	return (1);
}