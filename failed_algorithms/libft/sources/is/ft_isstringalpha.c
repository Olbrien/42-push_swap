/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstringalpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:32:12 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/23 17:53:45 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isstringalpha(char *string)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (string[i] != '\0')
	{
		if (ft_isalpha(string[i]) == 1)
			a = 1;
		else
			return (0);
		i++;
	}
	return (a);
}
