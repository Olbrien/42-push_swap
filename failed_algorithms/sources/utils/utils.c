/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:10:07 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 04:08:18 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	call4(char *string, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(string, "reverse rotate a") == 0)
	{
		write(1, "rra\n", 4);
		reverse_rotate_a(stack_a);
		return ;
	}
	else if (ft_strcmp(string, "reverse rotate b") == 0)
	{
		write(1, "rrb\n", 4);
		reverse_rotate_b(stack_b);
		return ;
	}
	else if (ft_strcmp(string, "reverse rotate a and b") == 0)
	{
		write(1, "rrr\n", 4);
		reverse_rotate_a_and_b(stack_a, stack_b);
		return ;
	}
	write(1, "WRONG INPUT!\n", 14);
}

void	call3(char *string, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(string, "rotate a") == 0)
	{
		write(1, "ra\n", 3);
		rotate_a(stack_a);
		return ;
	}
	else if (ft_strcmp(string, "rotate b") == 0)
	{
		write(1, "rb\n", 3);
		rotate_b(stack_b);
		return ;
	}
	else if (ft_strcmp(string, "rotate a and b") == 0)
	{
		write(1, "rr\n", 3);
		rotate_a_and_b(stack_a, stack_b);
		return ;
	}
	else
		call4(string, stack_a, stack_b);
}

void	call2(char *string, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(string, "push a") == 0)
	{
		write(1, "pa\n", 3);
		push_a(stack_a, stack_b);
		return ;
	}
	else if (ft_strcmp(string, "push b") == 0)
	{
		write(1, "pb\n", 3);
		push_b(stack_a, stack_b);
		return ;
	}
	else
		call3(string, stack_a, stack_b);
}

void	call(char *string, t_stack **stack_a, t_stack **stack_b)
{
	//debugger(*stack_a, *stack_b);
	if (ft_strcmp(string, "swap a") == 0)
	{
		write(1, "sa\n", 3);
		swap_a(stack_a);
		return ;
	}
	else if (ft_strcmp(string, "swap b") == 0)
	{
		write(1, "sb\n", 3);
		swap_b(stack_b);
		return ;
	}
	else if (ft_strcmp(string, "swap a and b") == 0)
	{
		write(1, "ss\n", 3);
		swap_a_and_b(stack_a, stack_b);
		return ;
	}
	else
		call2(string, stack_a, stack_b);
}
