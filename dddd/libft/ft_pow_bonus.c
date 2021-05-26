#include "libft.h"

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
