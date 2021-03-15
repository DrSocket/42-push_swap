#include "push_swap.h"

int		ft_tabcpy(int *dest, int *src, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (1);
}
