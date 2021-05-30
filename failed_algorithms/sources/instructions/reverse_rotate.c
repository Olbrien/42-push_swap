/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:16:29 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 15:40:50 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	int count;
	t_stack *temp_last;

	ft_lstgoto_begin_mod(stack_a);
	count = ft_lstsize_mod(*stack_a);

	if (count < 2)
		return ;

	ft_lstgoto_begin_mod(stack_a);
	temp_last = ft_lstnew_mod((*stack_a)->stack_nbr,
						(*stack_a)->stack_order_nbr);

	ft_lstremove_first_mod(stack_a);
	ft_lstadd_back_mod(stack_a, temp_last);

	ft_lstgoto_end_mod(stack_a);

}

void	reverse_rotate_b(t_stack **stack_b)
{
	int count;
	t_stack *temp_last;

	ft_lstgoto_begin_mod(stack_b);
	count = ft_lstsize_mod(*stack_b);

	if (count < 2)
		return ;

	ft_lstgoto_begin_mod(stack_b);
	temp_last = ft_lstnew_mod((*stack_b)->stack_nbr,
						(*stack_b)->stack_order_nbr);

	ft_lstremove_first_mod(stack_b);
	ft_lstadd_back_mod(stack_b, temp_last);
	ft_lstgoto_end_mod(stack_b);

}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
