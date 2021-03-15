#include "push_swap.h"

int		ft_numcheck(const char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] > 47 && str[i] < 58)
		i++;
	if (!(str[i] == '\0'))
	{
		write(1, "Argument Error", 15);
		return (0);
	}
	return (1);
}

int		fill_stack(t_struct *stack, char **str, int ac)
{
	int i;

	i = 0;
	stack->a.size = ac - 1;
	stack->b.size = 0;
	if (!(stack->a.tab = (int *)malloc(sizeof(int) * stack->a.size)) ||
		!(stack->b.tab = (int *)malloc(sizeof(int) * stack->a.size)))
	{
		write(1, "Stack Malloc Error\n", 20);
		return (0);
	}
	while (i < stack->a.size)
	{
		if (!ft_numcheck(str[i + 1]))
			return (0);
		stack->a.tab[i] = ft_atoi(str[i + 1]);
		stack->b.tab[i] = 0;
		i++;
	}
	return (1);
}

int		push_swap(int ac, char **str)
{
	t_struct	stack;
	int 		i;

	if (!fill_stack(&stack, str, ac))
		return (0);
	ft_push_b(&stack);
	ft_push_b(&stack);
	ft_push_b(&stack);
	ft_push_b(&stack);
	ft_push_b(&stack);

	i = 0;
	while (i < stack.a.size)
	{
		printf("\tTAB_A = %d\t\tTAB_B = %d\n", stack.a.tab[i], stack.b.tab[i]);
		i++;
	}
	free(stack.a.tab);
	free(stack.b.tab);
	return (1);
}

int main(int ac, char **av)
{
//	int arr[] = {10, 20, 30, 40, 50};
	if (ac > 1)
		push_swap(ac, av);
	return (0);
}