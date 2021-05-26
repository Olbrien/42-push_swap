/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four_to_five_args.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:07:36 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/26 06:50:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	prepare_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize_mod(*stack_b) == 2)
	{
		ft_lstgoto_end_mod(stack_b);
		if ((*stack_b)->stack_order_nbr < (*stack_b)->previous->stack_order_nbr)
			call("swap b", stack_a, stack_b);
	}
}

void	prepare_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	i;

	i = 0;
	count = (*stack_a)->stack_order_nbr;
	ft_lstgoto_begin_mod(stack_a);
	sorting_three_args(stack_a, stack_b);
	while (*stack_a != NULL)
	{
		if ((*stack_a)->next == NULL)
		{
			i = 0;
			break ;
		}
		if (count + 1 != (*stack_a)->next->stack_order_nbr)
			break ;
		(*stack_a) = (*stack_a)->next;
		i++;
	}


}

void	sorting_four_to_five_args(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstgoto_begin_mod(stack_a);
	ft_lstgoto_begin_mod(stack_b);
	if (is_stack_a_in_order(stack_a) == 1)
		return ;
	while (ft_lstsize_mod(*stack_a) != 3)
		call("push b", stack_a, stack_b);
	sorting_three_args(stack_a, stack_b);
	prepare_stack_b(stack_a, stack_b);
	while ((*stack_b) != NULL)
	{
		rotate_for_next_push_a(stack_a);
		call("push a", stack_a, stack_b);
	}
	while (is_stack_a_in_order(stack_a) == 0)
		call("rotate a", stack_a, stack_b);
	//debugger(*stack_a, *stack_b);
}
