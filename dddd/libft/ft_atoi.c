#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str && (*str == 43 || *str == 45))
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += (sign * (*(str++) - '0'));
		if (ret > 2147483647)
			return (-19999999);
		if (ret < -2147483648)
			return (-19999999);
	}
	return (ret);
}
