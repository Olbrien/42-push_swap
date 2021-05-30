/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:55:08 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 06:52:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_order_number2(t_stack **stack, int *numbers, int size)
{
	t_stack	*temp;
	int		i;
	int		y;
	int		order;

	temp = *stack;
	i = 0;
	y = 0;
	order = 0;
	while (i < size)
	{
		order = 0;
		y = 0;
		while (y < size)
		{
			if (numbers[i] > numbers[y])
				order++;
			y++;
		}
		(*stack)->order = order;
		*stack = (*stack)->next;
		i++;
	}
	*stack = temp;
}

void	set_order_number(t_stack **stack)
{
	t_stack		*start_loop;
	int			size;
	int			i;
	int			*numbers;

	size = ft_lstsize_mod(*stack);
	numbers = malloc(sizeof(int) * (size + 1));
	i = 0;
	start_loop = *stack;
	while (start_loop != NULL)
	{
		numbers[i] = (long)start_loop->number;
		start_loop = start_loop->next;
		i++;
	}
	set_order_number2(stack, numbers, size);
	free(numbers);
}

void	fill_stack_a(int argc, char **elems, t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 2;
	*stack = ft_lstnew_mod(ft_atoi(elems[1]), 0);
	while (i < argc)
	{
		tmp = ft_lstnew_mod(ft_atoi(elems[i]), 0);
		ft_lstadd_back_mod(stack, tmp);
		i++;
	}
	set_order_number(stack);
}
