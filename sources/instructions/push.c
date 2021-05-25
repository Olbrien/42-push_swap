/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 03:31:23 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 05:43:40 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *stack;

	if (*stack_b == NULL)
		return ;

	ft_lstgoto_end_mod(stack_a);
	ft_lstgoto_end_mod(stack_b);

	stack = ft_lstnew_mod((*stack_b)->stack_nbr, (*stack_b)->stack_order_nbr);
	ft_lstremove_last_mod(stack_b);

	ft_lstadd_back_mod(stack_a, stack);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *stack;

	if (*stack_a == NULL)
		return ;

	ft_lstgoto_end_mod(stack_a);
	ft_lstgoto_end_mod(stack_b);

	stack = ft_lstnew_mod((*stack_a)->stack_nbr, (*stack_a)->stack_order_nbr);
	ft_lstremove_last_mod(stack_a);

	ft_lstadd_back_mod(stack_b, stack);
}
