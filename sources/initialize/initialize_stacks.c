/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:36:04 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 03:38:50 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_order_number(t_stack **stack_a)
{
	t_stack *current;
	t_stack *loop;
	int number;
	int order;

	current = *stack_a;
	loop = *stack_a;
	while (current != NULL)
	{
		number = current->stack_nbr;
		order = 0;
		while (loop != NULL)
		{
			if (number > loop->stack_nbr)
				order++;
			if (loop->next == NULL)
				break ;
			loop = loop->next;
		}
		(*stack_a)->stack_order_nbr = order;
		ft_lstgoto_begin_mod(&loop);
		if (current->next == NULL || (*stack_a)->next == NULL)
			break ;
		current = current->next;
		*stack_a = (*stack_a)->next;
	}
	ft_lstgoto_begin_mod(stack_a);
}

void	initialize_stacks(t_stack **stack_a, t_stack **stack_b,
						char **argv, int argc)
{
	t_stack	*stack_add;
	int nbr_args;

	nbr_args = argc - 1;

	*stack_a = ft_lstnew_mod(ft_atoi(argv[nbr_args]), 0);
	while (nbr_args > 1)
	{
		nbr_args--;
		stack_add = ft_lstnew_mod(ft_atoi(argv[nbr_args]), 0);
		ft_lstadd_back_mod(stack_a, stack_add);
	}
	set_order_number(stack_a);

	*stack_b = NULL;
}
