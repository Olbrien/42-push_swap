/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_last2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:39:53 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/24 22:41:32 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstremove_last2(t_list2 **lst)
{
	t_list2	*current;

	if (!lst)
		return ;
	ft_lstgoto_begin2(lst);
	current = (*lst);
	if (ft_lstsize2((*lst)) < 2)
	{
		ft_lstclear2(lst);
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
