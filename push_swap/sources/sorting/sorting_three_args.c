/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:24:00 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 02:46:42 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_three_args(t_stack **stack_a, t_stack **stack_b)
{
	while (is_stack_in_order(*stack_a) == 0)
	{
		if ((*stack_a)->order == 2)
			call("rotate a", stack_a, stack_b);
		else if ((*stack_a)->next->order > (*stack_a)->order)
			call("reverse rotate a", stack_a, stack_b);
		else if ((*stack_a)->order > (*stack_a)->next->order)
			call("swap a", stack_a, stack_b);
	}
}
