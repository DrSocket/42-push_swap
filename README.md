## Push Swap ![lucisanc's 42 ft_containers Score](https://badge42.vercel.app/api/v2/cl3vpat6c006909l0j733osv1/project/2572478)

A sorting algorithem problem where we must sort a stack with certain constraints. 

It is coded fully in C and the only external functions allowed are: read, write, malloc, free, exit

Complexity is checked by maximum number of operation per arguments:
-For 5 arguments it cannot be more than 12. In the case of my program it is never more than 5.
-For 100 arguments the maximum number of instructions is 700. 
-For 500 arguments the maximum number of instructions to get a score of 100 is 5500. This program had 6000 max, therefore the 96/100.

2 stacks are available throughout the program
Stack A contains the numbers passed as arguments.
Stack B begins empty. 

The only operations available are:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a- take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : pushb- take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

##### Launch program

`./push_swap i j k [...more numbers...] `
