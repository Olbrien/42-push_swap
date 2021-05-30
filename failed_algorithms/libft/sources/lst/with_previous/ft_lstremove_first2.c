/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_first2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 06:29:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/25 06:31:01 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstremove_first2(t_list2 **lst)
{
	if (!lst || (*lst) == NULL)
		return ;
	ft_lstgoto_begin2(lst);
	if (ft_lstsize2((*lst)) < 2)
	{
		ft_lstclear2(lst);
		return ;
	}
	ft_lstgoto_begin2(lst);
	if ((*lst)->next != NULL)
	{
		(*lst) = (*lst)->next;
		free((*lst)->previous);
		(*lst)->previous = NULL;
	}
}
