#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft.h"

typedef struct	s_stack
{
	int			*tab;
	int			begin;
	int			size;
}				t_stack;

typedef struct	s_struct
{
	t_stack		stack_a;
	t_stack		stack_b;
}				t_struct;

#endif