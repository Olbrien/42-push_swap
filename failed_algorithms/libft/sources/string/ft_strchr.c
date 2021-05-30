/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:14:08 by marvin            #+#    #+#             */
/*   Updated: 2021/05/23 04:42:33 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)str;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
		new_str++;
	}
	return (new_str);
}
