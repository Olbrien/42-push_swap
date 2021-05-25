/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:19:46 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 03:20:28 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstremove_last(t_stack **lst)
{
	t_stack	*current;

	if (!lst || (*lst) == NULL)
		return ;
	ft_lstgoto_begin_mod(lst);
	current = (*lst);
	if (ft_lstsize_mod((*lst)) < 2)
	{
		ft_lstclear_mod(lst);
		return ;
	}
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			current = current->previous;
			free(current->next);
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
}

int	ft_lstsize_mod(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stack *ft_lstgoto_end_mod(t_stack **lst)
{
	if (!lst || (*lst) == NULL)
		return (NULL);
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	return (*lst);
}

t_stack *ft_lstgoto_begin_mod(t_stack **lst)
{
	if (!lst || (*lst) == NULL)
		return (NULL);
	while ((*lst)->previous != NULL)
		(*lst) = (*lst)->previous;
	return (*lst);
}
