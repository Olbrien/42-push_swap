/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:30:43 by tisantos          #+#    #+#             */
/*   Updated: 2021/05/24 02:34:00 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	exit_error(char *string)
{
	write(2, string, ft_strlen(string));
	return (0);
}

int	are_there_duplicates2(char **argv, char **temp, int i, int a)
{
	int	char_count;

	char_count = 0;
	if (ft_strcmp(argv[i], "0") == 0 || ft_strcmp(argv[i], "-0") == 0)
	{
		if (ft_strcmp(temp[a], "0") == 0 || ft_strcmp(temp[a], "-0") == 0)
			char_count++;
	}
	else if (ft_strcmp(argv[i], temp[a]) == 0)
		char_count++;
	a++;
	return(char_count);
}

int	are_there_duplicates(char **argv)
{
	int		i;
	int		a;
	int		char_count;
	char	**temp;

	temp = argv;
	i = 1;
	while (argv[i] != NULL)
	{
		a = 1;
		char_count = 0;
		while (temp[a] != NULL)
		{
			char_count += are_there_duplicates2(argv, temp, i, a);
			a++;
		}
		if (char_count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	is_bigger_than_integer(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strlen(argv[i]) > 2)
		{
			if (ft_atoi(argv[i]) == 0 || ft_atoi(argv[i]) == -1)
				return(1);
		}
		i++;
	}
	return (0);
}

int	error_handling(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc <= 2)
		return (0);
	while (argv[i] != NULL)
	{
		if (ft_isstringdigit(argv[i]) == 0)
			return(0);
		i++;
	}
	if (is_bigger_than_integer(argv) == 1)
		return (0);
	if (are_there_duplicates(argv) == 1)
		return (0);
	return (1);

}
