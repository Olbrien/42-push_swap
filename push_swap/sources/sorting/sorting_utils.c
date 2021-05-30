/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:57:39 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 03:04:20 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_stack_in_order(t_stack *stack)
{
	int	order;

	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		order = stack->order;
		stack = stack->next;
		if (order >= stack->order)
			return (0);
	}
	return (1);
}

int	find_next(t_stack *che, int len, int range)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = che;
	while (tmp)
	{
		if (tmp->order >= (len - range))
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int	find_spec_next(t_stack *che, int len, int num)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = che;
	while (tmp != NULL)
	{
		if (tmp->order == num)
		{
			if (count > (len / 2))
				return (0);
			else
				return (1);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int	find_hi(t_stack *stac)
{
	t_stack	*tmp;
	int		ret;

	ret = 0;
	tmp = stac;
	while (stac)
	{
		if (stac->order > ret)
			ret = stac->order;
		stac = stac->next;
	}
	stac = tmp;
	return (ret);
}

int	put_back_a(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	n = find_hi(*stack_b);
	while (ft_lstsize_mod(*stack_b) > 0)
	{
		if ((*stack_b)->order == n)
		{
			call("push a", stack_a, stack_b);
			n--;
		}
		else if (find_spec_next(*stack_b, ft_lstsize_mod(*stack_b), n) == 0)
		{
			while ((*stack_b)->order != n)
				call("reverse rotate b", stack_a, stack_b);
		}
		else
		{
			while ((*stack_b)->order != n)
				call("rotate b", stack_a, stack_b);
		}
	}
	return (1);
}
