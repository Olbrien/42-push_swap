/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 06:41:01 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 06:49:47 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_reverse_rotate2(t_list2 **stack_a)
{
	int		count;
	t_list2	*temp_last;

	ft_lstgoto_begin2(stack_a);
	count = ft_lstsize2(*stack_a);
	if (count < 2)
		return ;
	ft_lstgoto_begin2(stack_a);
	temp_last = ft_lstnew2((*stack_a)->content);
	ft_lstremove_first2(stack_a);
	ft_lstadd_back2(stack_a, temp_last);
}
