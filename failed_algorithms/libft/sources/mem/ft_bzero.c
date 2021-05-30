/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 03:18:04 by marvin            #+#    #+#             */
/*   Updated: 2021/05/23 04:41:52 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str_ptr;
	size_t			i;

	str_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str_ptr[i] = 0;
		i++;
	}
}
