/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 05:39:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 03:37:21 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstclear_mod(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	if (!lst || (*lst) == NULL)
		return ;
	current = *lst;
	while (current->previous != NULL)
		current = current->previous;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_lstadd_front_mod(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		(*lst)->previous = new;
		*lst = new;
	}
}

void	ft_lstadd_back_mod(t_stack **lst, t_stack *new)
{
	t_stack		*begin;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	if (lst && (*lst) && new)
	{
		begin = (*lst);
		if (begin == NULL)
			(*lst) = new;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
			begin->next->previous = begin;
		}
	}
}

t_stack	*ft_lstnew_mod(int stack_nbr, int stack_order_nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	if (new)
	{
		new->stack_nbr = stack_nbr;
		new->stack_order_nbr = stack_order_nbr;
		new->next = NULL;
		new->previous = NULL;
	}
	return (new);
}
