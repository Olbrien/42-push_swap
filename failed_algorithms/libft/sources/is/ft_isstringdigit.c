/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstringdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:32:51 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/23 18:15:08 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isstringdigit(char *string)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (string[i] != '\0')
	{
		if (i == 0 && string[i] == '-')
		{
			i++;
			continue ;
		}
		if (ft_isdigit(string[i]) == 1)
			a = 1;
		else
			return (0);
		i++;
	}
	return (a);
}
