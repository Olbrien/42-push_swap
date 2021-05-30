/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_two_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:43:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 05:28:53 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sorting_two_args(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_in_order(*stack_a) == 1)
		return ;
	call("swap a", stack_a, stack_b);
	sorting_two_args(stack_a, stack_b);
}
