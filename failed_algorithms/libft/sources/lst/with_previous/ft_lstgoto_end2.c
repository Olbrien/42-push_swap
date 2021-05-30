/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgoto_end2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:15:17 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/24 17:15:52 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_list2	*ft_lstgoto_end2(t_list2 **lst)
{
	if (!lst)
		return (NULL);
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	return (*lst);
}
