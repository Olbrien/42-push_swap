/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 06:48:59 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 06:50:46 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_push2(t_list2 **stack_a, t_list2 **stack_b)
{
	t_list2	*stack;

	if (*stack_b == NULL)
		return ;
	ft_lstgoto_end2(stack_a);
	ft_lstgoto_end2(stack_b);
	stack = ft_lstnew2((*stack_b)->content);
	ft_lstremove_last2(stack_b);
	ft_lstadd_back2(stack_a, stack);
}
