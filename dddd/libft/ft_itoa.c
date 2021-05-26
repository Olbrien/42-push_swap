#include "libft.h"

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
