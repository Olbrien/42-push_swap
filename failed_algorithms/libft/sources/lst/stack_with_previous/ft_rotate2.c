/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 06:51:31 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 06:52:48 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_rotate2(t_list2 **stack_a)
{
	int		count;
	t_list2	*temp_last;

	ft_lstgoto_begin2(stack_a);
	count = ft_lstsize2(*stack_a);
	if (count < 2)
		return ;
	ft_lstgoto_end2(stack_a);
	temp_last = ft_lstnew2((*stack_a)->content);
	ft_lstremove_last2(stack_a);
	ft_lstadd_front2(stack_a, temp_last);
}
