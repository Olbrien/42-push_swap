/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_call.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:23:03 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/29 20:33:16 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	call4(char *string, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(string, "reverse rotate a") == 0)
	{
		write(1, "rra\n", 4);
		rev_rot_stack(stack_a);
		return ;
	}
	else if (ft_strcmp(string, "reverse rotate b") == 0)
	{
		write(1, "rrb\n", 4);
		rev_rot_stack(stack_b);
		return ;
	}
	else if (ft_strcmp(string, "reverse rotate a and b") == 0)
	{
		write(1, "rrr\n", 4);
		rev_rot_stack(stack_a);
		rev_rot_stack(stack_b);
		return ;
	}
	write(1, "WRONG INPUT!\n", 14);
}

void	call3(char *string, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(string, "rotate a") == 0)
	{
		write(1, "ra\n", 3);
		rot_stack(stack_a);
		return ;
	}
	else if (ft_strcmp(string, "rotate b") == 0)
	{
		write(1, "rb\n", 3);
		rot_stack(stack_b);
		return ;
	}
	else if (ft_strcmp(string, "rotate a and b") == 0)
	{
		write(1, "rr\n", 3);
		rot_stack(stack_a);
		rot_stack(stack_b);
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
		push_stack(stack_a, stack_b);
		return ;
	}
	else if (ft_strcmp(string, "push b") == 0)
	{
		write(1, "pb\n", 3);
		push_stack(stack_b, stack_a);
		return ;
	}
	else
		call3(string, stack_a, stack_b);
}

void	call(char *string, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(string, "swap a") == 0)
	{
		write(1, "sa\n", 3);
		swap_stack(stack_a);
		return ;
	}
	else if (ft_strcmp(string, "swap b") == 0)
	{
		write(1, "sb\n", 3);
		swap_stack(stack_b);
		return ;
	}
	else if (ft_strcmp(string, "swap a and b") == 0)
	{
		write(1, "ss\n", 3);
		swap_stack(stack_a);
		swap_stack(stack_b);
		return ;
	}
	else
		call2(string, stack_a, stack_b);
}
