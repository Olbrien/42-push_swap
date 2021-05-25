/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:30:13 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/24 18:30:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstadd_front2(t_list2 **lst, t_list2 *new)
{
	if (lst && new)
	{
		new->next = *lst;
		(*lst)->previous = new;
		*lst = new;
	}
}
