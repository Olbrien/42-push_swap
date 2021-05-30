/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:26:01 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 05:44:59 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct s_stack
{
	int				number;
	int				order;
	struct s_stack	*next;
}				t_stack;

/*
** Error Handling
*/

int				error_handling(int argc, char **argv);
int				exit_error(char *string);

/*
** Initialize
*/

void			fill_stack_a(int no_elems, char **elems, t_stack **stack);

/*
** Lst
*/

t_stack			*ft_lstnew_mod(int number, int order);
void			ft_lstadd_back_mod(t_stack **lst, t_stack *new);
int				ft_lstsize_mod(t_stack *lst);
void			ft_lstadd_front_mod(t_stack **lst, t_stack *new);
void			ft_lstclear_mod(t_stack **lst);

/*
** Instructions
*/

void			rot_stack(t_stack **stack);
void			rev_rot_stack(t_stack **stack);
void			swap_stack(t_stack **stack);
void			push_stack(t_stack **dest, t_stack **src);

void			call(char *string, t_stack **stack_a, t_stack **stack_b);

/*
** Sorting
*/

void			sorting_two_args(t_stack **stack_a, t_stack **stack_b);
void			sorting_three_args(t_stack **stack_a, t_stack **stack_b);
void			sorting_four_args(t_stack **stack_a, t_stack **stack_b);
void			sorting_five_args(t_stack **stack_a, t_stack **stack_b);
void			sorting_big_args(t_stack **stack_a, t_stack **stack_b);

int				is_stack_in_order(t_stack *stack);
int				put_back_a(t_stack **stack_a, t_stack **stack_b);
int				find_hi(t_stack *stac);
int				find_spec_next(t_stack *che, int len, int num);
int				find_next(t_stack *che, int len, int range);

#endif
