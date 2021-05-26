/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:18:27 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 20:23:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_two_args(t_stack **stack_a, t_stack **stack_b)
{
	//debugger(*stack_a, *stack_b);
	//printf("--------------------------------------------------------\n");

	if (is_stack_a_in_order(stack_a) == 1)
		return ;
	call("swap a", stack_a, stack_b);
	sorting_two_args(stack_a, stack_b);
}
