/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:16:35 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 05:50:11 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_stack_a_in_order(t_stack *stack_a)
{
	int	not_in_order;

	not_in_order = 0;
	ft_lstgoto_begin_mod(&stack_a);
	while (stack_a != NULL)
	{
		if (stack_a->next == NULL)
			break ;
		if (stack_a->stack_nbr <= stack_a->next->stack_nbr)
			not_in_order++;
		(stack_a) = (stack_a)->next;
	}
	if (not_in_order > 0)
		return (0);
	else
		return (1);
}
