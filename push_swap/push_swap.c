/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:25:45 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 05:27:26 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (error_handling(argc, argv) == 0)
		return (exit_error("Error\n"));
	fill_stack_a(argc, argv, &stack_a);
	if (is_stack_in_order(stack_a) == 1)
		;
	else if (ft_lstsize_mod(stack_a) == 2)
		sorting_two_args(&stack_a, &stack_b);
	else if (ft_lstsize_mod(stack_a) == 3)
		sorting_three_args(&stack_a, &stack_b);
	else if (ft_lstsize_mod(stack_a) == 4)
		sorting_four_args(&stack_a, &stack_b);
	else if (ft_lstsize_mod(stack_a) == 5)
		sorting_five_args(&stack_a, &stack_b);
	else if (ft_lstsize_mod(stack_a) >= 6)
		sorting_big_args(&stack_a, &stack_b);
	ft_lstclear_mod(&stack_a);
	ft_lstclear_mod(&stack_b);
}
