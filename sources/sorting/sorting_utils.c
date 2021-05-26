/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:16:35 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/26 02:55:51 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_stack_a_in_order(t_stack **stack_a)
{
	int	not_in_order;

	not_in_order = 0;
	ft_lstgoto_begin_mod(stack_a);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->next == NULL)
			break ;
		if ((*stack_a)->stack_nbr <= (*stack_a)->next->stack_nbr)
			not_in_order++;
		(*stack_a) = (*stack_a)->next;
	}
	ft_lstgoto_begin_mod(stack_a);
	if (not_in_order > 0)
		return (0);
	else
		return (1);
}

int	stack_a_has_all_elements(t_stack **stack_a)
{
	int	was_order_zero_found;

	was_order_zero_found = 0;
	ft_lstgoto_begin_mod(stack_a);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->stack_order_nbr == 0)
			was_order_zero_found = 1;
		if ((*stack_a)->next == NULL)
			break ;
		(*stack_a) = (*stack_a)->next;
	}
	ft_lstgoto_begin_mod(stack_a);
	return (was_order_zero_found);
}

int	is_top_nbr_smaller_than_prev_nbr(t_stack **stack_a)
{
	ft_lstgoto_end_mod(stack_a);

	if ((*stack_a)->previous == NULL)
		return (1);

	if ((*stack_a)->stack_order_nbr < (*stack_a)->previous->stack_order_nbr)
		return (1);
	else
		return (0);

}

int	is_top_stack_a_smallest_order_nbr(t_stack **stack_a)
{
	int	order;
	int is_smaller;

	ft_lstgoto_end_mod(stack_a);
	order = (*stack_a)->stack_order_nbr;
	is_smaller = 1;

	while ((*stack_a) != NULL)
	{
		if (order > (*stack_a)->stack_order_nbr)
			is_smaller = 0;
		if ((*stack_a)->previous == NULL)
			break ;
		(*stack_a) = (*stack_a)->previous;
	}
	ft_lstgoto_begin_mod(stack_a);
	return (is_smaller);
}
