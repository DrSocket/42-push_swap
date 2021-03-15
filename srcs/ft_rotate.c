#include "push_swap.h"

int		ft_rotate(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	tmp = tab[0];
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		tab[i + 1] = tmp;
		i++;
	}
	return (1);
}

int		ft_rotate_a(t_struct *stack)
{
	ft_rotate(stack->a.tab, stack->a.size);
	return (1);
}

int		ft_rotate_b(t_struct *stack)
{
	ft_rotate(stack->b.tab, stack->b.size);
	return (1);
}

int		ft_rboth(t_struct *stack)
{
	ft_rotate(stack->a.tab, stack->a.size);
	ft_rotate(stack->b.tab, stack->b.size);
	return (1);
}