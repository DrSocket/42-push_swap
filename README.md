# push_swap

Push Swap - 42

A sorting algorithem problem where we must sort a stack with certain constraints. 

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

Launch program:

./push_swap i j k [...more numbers...] 