/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:38:44 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 14:52:37 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_a(t_stack **stack_a)
{
	int count;
	t_stack *temp_last;
	t_stack *temp_second_from_last;

	ft_lstgoto_begin_mod(stack_a);
	count = ft_lstsize_mod(*stack_a);

	if (count < 2)
		return ;

	ft_lstgoto_end_mod(stack_a);
	temp_last = ft_lstnew_mod((*stack_a)->stack_nbr,
						(*stack_a)->stack_order_nbr);
	(*stack_a) = (*stack_a)->previous;
	temp_second_from_last = ft_lstnew_mod((*stack_a)->stack_nbr,
						(*stack_a)->stack_order_nbr);
	ft_lstremove_last_mod(stack_a);
	ft_lstremove_last_mod(stack_a);

	ft_lstadd_back_mod(stack_a, temp_last);
	ft_lstadd_back_mod(stack_a, temp_second_from_last);

	ft_lstgoto_begin_mod(stack_a);
}

void	swap_b(t_stack **stack_b)
{
	int count;
	t_stack *temp_last;
	t_stack *temp_second_from_last;

	ft_lstgoto_begin_mod(stack_b);
	count = ft_lstsize_mod(*stack_b);

	if (count < 2)
		return ;

	ft_lstgoto_end_mod(stack_b);
	temp_last = ft_lstnew_mod((*stack_b)->stack_nbr,
						(*stack_b)->stack_order_nbr);
	(*stack_b) = (*stack_b)->previous;
	temp_second_from_last = ft_lstnew_mod((*stack_b)->stack_nbr,
						(*stack_b)->stack_order_nbr);
	ft_lstremove_last_mod(stack_b);
	ft_lstremove_last_mod(stack_b);

	ft_lstadd_back_mod(stack_b, temp_last);
	ft_lstadd_back_mod(stack_b, temp_second_from_last);

	ft_lstgoto_begin_mod(stack_b);
}

void	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
