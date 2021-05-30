/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 03:31:23 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 15:41:34 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *stack;
	t_stack *stack_a_temp;
	t_stack *stack_b_temp;

	stack_a_temp = *stack_a;
	stack_b_temp = *stack_b;

	if (*stack_b == NULL)
		return ;

	ft_lstgoto_end_mod(stack_a);
	ft_lstgoto_end_mod(stack_b);

	stack = ft_lstnew_mod((*stack_b)->stack_nbr, (*stack_b)->stack_order_nbr);
	ft_lstremove_last_mod(stack_b);

	ft_lstadd_back_mod(stack_a, stack);

	*stack_a = stack_a_temp;
	*stack_b = stack_b_temp;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *stack;
	t_stack *stack_a_temp;
	t_stack *stack_b_temp;

	if (*stack_a == NULL)
		return ;

	stack_a_temp = *stack_a;
	stack_b_temp = *stack_b;

	ft_lstgoto_end_mod(stack_a);
	ft_lstgoto_end_mod(stack_b);

	stack = ft_lstnew_mod((*stack_a)->stack_nbr, (*stack_a)->stack_order_nbr);
	ft_lstremove_last_mod(stack_a);

	ft_lstadd_back_mod(stack_b, stack);

	ft_lstgoto_begin_mod(stack_a);
	ft_lstgoto_begin_mod(stack_b);

	*stack_a = stack_a_temp;
	*stack_b = stack_b_temp;
}
