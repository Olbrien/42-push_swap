/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:10:20 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/23 04:41:49 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long	ft_pow(int number, unsigned int power)
{
	long long	temp;

	temp = number;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		temp *= number;
		power--;
	}
	return (temp);
}
