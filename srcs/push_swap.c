#include "push_swap.h"


int     push_swap(char *int_str)
{
    printf("%s\n", int_str);
}

int main(int ac, char **av)
{
    int i = 0;

/*    while (av[1][i])
    {
        printf("one: %c", av[1][i]);
        i++;
    }
*/  
    printf("%i\n", ac);
    printf("%s\n", av[3]);
    if (ac == 2)
        push_swap(av[1]);
    return (1);
}