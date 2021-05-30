/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 04:56:14 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 05:58:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_chunk(t_stack **stack_a, t_stack **stack_b, int len, int chunks)
{
	int	slen;

	slen = ft_lstsize_mod(*stack_b);
	while ((ft_lstsize_mod(*stack_b) - slen) <= (len / chunks))
	{
		if ((*stack_a)->order >= (len - (len / chunks)))
			call("push b", stack_a, stack_b);
		else
		{
			if (find_next(*stack_a, len, (len / chunks)) == 1)
			{
				while (!((*stack_a)->order >= (len - (len / chunks))))
					call("rotate a", stack_a, stack_b);
			}
			else
			{
				while (!((*stack_a)->order >= (len - (len / chunks))))
					call("reverse rotate a", stack_a, stack_b);
			}
		}
	}
	return (1);
}

void	sorting_big_args(t_stack **stack_a, t_stack **stack_b)
{
	int	chunks;
	int	len;

	if (ft_lstsize_mod(*stack_a) <= 100)
		chunks = 5;
	else
		chunks = 7;
	len = ft_lstsize_mod(*stack_a);
	while (ft_lstsize_mod(*stack_a) >= 5)
	{
		get_chunk(stack_a, stack_b, len - 1, chunks);
		len = ft_lstsize_mod(*stack_a);
	}
	sorting_four_args(stack_a, stack_b);
}
