/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucisanc <lucisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:01:43 by lucisanc          #+#    #+#             */
/*   Updated: 2022/02/27 10:06:26 by lucisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

#define ANSI_RED     "\x1b[31m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_RESET   "\x1b[0m"

typedef enum	e_move
{
	move_a,
	move_b,
	move_ab
}				t_move;

typedef struct	s_quicksort
{
	int	partition;
	int	size;
	int	*array;
}				t_quicksort;

typedef struct	s_stck_elem
{
	long int			nb;
	bool				to_push;
	size_t				index;
	struct s_stck_elem	*prev;
	struct s_stck_elem	*next;
}				t_stck_elem;

typedef struct	s_stck
{
	size_t		stck_size;
	size_t		to_push_nbr;
	t_stck_elem	*head;
	t_stck_elem	*markup_head;
	size_t		n_one;
	size_t		n_two;
	long		depth_one;
	long		depth_two;
}				t_stck;

typedef struct	s_swap
{
	int		*array;
	size_t	size_array;
	t_stck	*a;
	t_stck	*b;
	size_t	nbr_move;
}				t_swap;

/*
 *	main.c
 */

void		error_exit(t_stck_elem *lst);
void		init(t_swap *swap, t_stck *a, t_stck *b);

/*
 * lst_utils.c
 */

void		lst_add_to_stack(t_stck_elem **begin,
				size_t *size_stck,
				long int nb);
void		lst_create_head(t_stck_elem **begin, long int nb);
t_stck_elem	*lst_get_last(t_stck_elem *stck);
void		lst_join_begin_last(t_stck_elem *first);
t_stck_elem	*lst_new_node(long int nb);

/*
 *	parsing_utils.c
 */
void		check_nb_repeat(t_stck_elem *lst, long int nb, size_t size);
void		check_valid_input(t_swap *swap, char *str, int tmp);
int			ft_atoi_err(long *nb, char **av);
void		parsing(t_swap *swap, int ac, char **av);

/*
 *	presort.c
 */

int			*init_quicksort(t_stck_elem *lst, size_t size_lst,
				size_t *size_array);

/*
 *	markup.c
 */

void		get_best_markup_head(t_swap *swap,
				t_stck_elem *head);
void		lst_index(t_stck_elem *stck,
				size_t s_stck,
				int *array,
				size_t s_array);
size_t		markup_index(size_t stck_size,
				t_stck_elem *markup_head,
				bool to_write);

/*
 *	sort.c
 */

t_stck_elem	*get_move_elem(t_stck *a, t_stck *b, long *nbr_a, long *nbr_b);
void		stack_a(t_swap *swap, t_stck *a);

void		stack_b(t_swap *swap, t_stck *a, t_stck *b);

/*
 *	sort_small.c
 */

void		align_stck(t_swap *swap, t_stck *stck);
void		sort_three(t_swap *swap, t_stck_elem *a);
void		sort_five(t_swap *swap, t_stck *a, t_stck *b);

/*
 *	sort_utils.c
 */

t_stck_elem	*find_elem(t_stck *stck, size_t index);
long		get_number_move(t_stck *stck, t_stck_elem *elem);

/*
 *	push.c
 */

void		move_push(t_swap *swap, t_move move);

/*
 *	rotate.c
 */

void		move_rotate(t_swap *swap, t_move move);
void		move_reverse_rotate(t_swap *swap, t_move move);

/*
 *	swap.c
 */

void		fswap(t_stck_elem **top);
void		move_swap(t_swap *swp, t_move move);

/*
 *	utils.c
 */

void		destroy_lst(t_stck_elem **stck);
long		ft_abs(long nb);
void		ft_putnbr_fd(int nb, int fd);
int			is_sorted(t_swap *swap);
void		move_x(void (*move)(t_swap *, t_move),
				t_swap *swap, t_move mv, long nbr);

/*
 *	NOT USED FOR FINAL SUBMISSION
 *	OPTIMISATION PAST 100 FAIL
 */

/*
 *	insertion_sort.c
 */

void		insertion_sort(t_swap *swap);
void		align_b(t_swap *swap);

/*
 *	test_print_stcks.c
 */

void		print_stack(t_swap *swap);

#endif
