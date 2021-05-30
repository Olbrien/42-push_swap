/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:06:38 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/30 06:12:25 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rot_stack(t_stack **stack)
{
	t_stack	*add;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	add = *stack;
	*stack = add->next;
	add->next = NULL;
	ft_lstadd_back_mod(stack, add);
}

void	rev_rot_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*add;
	int		len;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	len = ft_lstsize_mod(*stack);
	temp = *stack;
	while (len > 2)
	{
		temp = temp->next;
		len--;
	}
	add = temp->next;
	temp->next = NULL;
	ft_lstadd_front_mod(stack, add);
}

void	push_stack(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if ((*src) == NULL)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = NULL;
	ft_lstadd_front_mod(dest, temp);
}

void	swap_stack(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	bottom = top->next;
	*stack = bottom;
	top->next = bottom->next;
	bottom->next = top;
}
