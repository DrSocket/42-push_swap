#include "push_swap.h"

int		ft_push(int *dest, int *src, int size_dest, int size_src)
{
	int i;
	int *temp_tab;

	i = 0;
	temp_tab = (int *)malloc(size_dest + size_src);
	temp_tab[0] = src[0];
	ft_tabcpy((temp_tab + 1), dest, size_dest);
	ft_tabcpy(dest, temp_tab, size_dest);
	ft_tabcpy(src, (src + 1), size_src);
	free(temp_tab);
	return (1);
}

int		ft_push_a(t_struct *stack)
{
	if (stack->b.size > 0)
	{
		stack->a.size++;
		stack->b.size--;
		ft_push(stack->a.tab, stack->b.tab, stack->a.size, stack->b.size);
	}
	return (1);
}

int		ft_push_b(t_struct *stack)
{
	if (stack->a.size > 0)
	{
		stack->b.size++;
		stack->a.size--;
		ft_push(stack->b.tab, stack->a.tab, stack->b.size, stack->a.size);
	}
	return (1);
}