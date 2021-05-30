/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgoto_begin2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:16:25 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/24 17:18:48 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_list2	*ft_lstgoto_begin2(t_list2 **lst)
{
	if (!lst)
		return (NULL);
	while ((*lst)->previous != NULL)
		(*lst) = (*lst)->previous;
	return (*lst);
}
