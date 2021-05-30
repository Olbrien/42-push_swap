/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 02:59:18 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 05:12:49 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_five_args(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize_mod(*stack_a) > 3)
	{
		if (find_next(*stack_a, ft_lstsize_mod(*stack_a), 4) == 0)
		{
			while ((*stack_a)->order > 1)
				call("rotate a", stack_a, stack_b);
			call("push b", stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->order > 1)
				call("reverse rotate a", stack_a, stack_b);
			call("push b", stack_a, stack_b);
		}
	}
	sorting_three_args(stack_a, stack_b);
	put_back_a(stack_a, stack_b);
}
