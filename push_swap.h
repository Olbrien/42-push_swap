/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:18:22 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 05:13:55 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

typedef struct s_stack_info
{
	int			stack_nbr;
	int			stack_order_nbr;
}			t_stack_info;

typedef struct s_stack
{
	int			stack_nbr;
	int			stack_order_nbr;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

/*
** Error Handling
*/

int				error_handling(int argc, char **argv);
int				exit_error(char *string);

/*
** Initialize Stacks
*/

void			set_order_number(t_stack **stack_a);
void			initialize_stacks(t_stack **stack_a, t_stack **stack_b,
								char **argv, int argc);

/*
** Instructions
*/

void			swap_a(t_stack **stack_a);
void			swap_b(t_stack **stack_b);
void			swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

void			push_a(t_stack **stack_a, t_stack **stack_b);
void			push_b(t_stack **stack_a, t_stack **stack_b);

void			rotate_a(t_stack **stack_a);
void			rotate_b(t_stack **stack_b);
void			rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);


/*
**	Lst
*/

t_stack			*ft_lstnew_mod(int stack_nbr, int stack_order_nbr);
void			ft_lstclear_mod(t_stack **lst);
void			ft_lstadd_back_mod(t_stack **lst, t_stack *new);
t_stack			*ft_lstgoto_begin_mod(t_stack **lst);
t_stack			*ft_lstgoto_end_mod(t_stack **lst);
void			ft_lstadd_front_mod(t_stack **lst, t_stack *new);
int				ft_lstsize_mod(t_stack *lst);
void			ft_lstremove_last(t_stack **lst);

#endif
