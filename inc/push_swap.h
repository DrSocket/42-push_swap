#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft.h"

typedef struct	s_min
{
	int		min;
	int		i;
} 				t_min;

typedef	struct	s_stack
{
	int		*tab;
	int		start;
	int		size;
}				t_stack;

typedef struct 	s_struct
{
	t_stack	a;
	t_stack	b;
}				t_struct;

int		push_swap(int ac, char **str);
int		fill_stack(t_struct *stack, char **str, int ac);
int		ft_numcheck(const char *str);
int		ft_tabcpy(int *dest, int *src, int size);
int		ft_push(int *tab_a, int *tab_b, int size_a, int size_b);
int		ft_push_a(t_struct *stack);
int		ft_push_b(t_struct *stack);
int		ft_swap(int *tab);
int		ft_swap_a(t_struct *stack);
int		ft_swap_b(t_struct *stack);
int		ft_swapboth(t_struct *stack);
int		ft_rotate(int *tab, int size);
int		ft_rotate_a(t_struct *stack);
int		ft_rotate_b(t_struct *stack);
int		ft_rboth(t_struct *stack);
int		ft_rra(int *tab, int size);
int		ft_rra_a(t_struct *stack);
int		ft_rra_b(t_struct *stack);
int		ft_rrboth(t_struct *stack);

#endif