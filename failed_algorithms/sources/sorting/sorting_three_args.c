/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:11:58 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 05:45:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_three_args_method(t_stack **stack_a, t_stack **stack_b, int method)
{
	ft_lstgoto_begin_mod(stack_a);
	if (is_stack_a_in_order(*stack_a) == 1)
		return ;
	if (method == 2)
	{
		call("reverse rotate a", stack_a, stack_b);
		call("swap a", stack_a, stack_b);
	}
	else if (method == 1)
	{
		call("reverse rotate a", stack_a, stack_b);
		ft_lstgoto_end_mod(stack_a);
		if ((*stack_a)->stack_order_nbr > (*stack_a)->previous->stack_order_nbr)
			call("swap a", stack_a, stack_b);
		call("reverse rotate a", stack_a, stack_b);
	}
	else if (method == 0)
	{
		ft_lstgoto_end_mod(stack_a);
		if ((*stack_a)->stack_nbr > (*stack_a)->previous->stack_nbr)
			call("swap a", stack_a, stack_b);
		call("reverse rotate a", stack_a, stack_b);
	}
}

int	smallest_order_nbr(t_stack *stack_a)
{
	int first;
	int second;
	int third;

	ft_lstgoto_begin_mod(&stack_a);

	first = stack_a->stack_order_nbr;
	second = stack_a->next->stack_order_nbr;
	third = stack_a->next->next->stack_order_nbr;

	if (first < second && first < third)
		return (first);
	else if (second < third)
		return (second);
	else
		return (third);
}

void	sorting_three_args(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	smallest_order_number;

	i = 0;
	ft_lstgoto_begin_mod(stack_a);
	smallest_order_number = smallest_order_nbr(*stack_a);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->stack_order_nbr == smallest_order_number)
		{
			sorting_three_args_method(stack_a, stack_b, i);
			break ;
		}
		if ((*stack_a)->next == NULL)
			break ;
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	ft_lstgoto_begin_mod(stack_a);
}
