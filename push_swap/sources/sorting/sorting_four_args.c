/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 02:13:29 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 05:29:01 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_four_args(t_stack **stack_a, t_stack **stack_b)
{
	while (((*stack_a)->order) != 3)
		call("rotate a", stack_a, stack_b);
	call("push b", stack_a, stack_b);
	sorting_three_args(stack_a, stack_b);
	put_back_a(stack_a, stack_b);
	while (is_stack_in_order(*stack_a) == 0)
		call("reverse rotate a", stack_a, stack_b);
}
