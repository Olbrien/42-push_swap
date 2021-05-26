#include "libft.h"

int	ft_tolower(int c)
{
	int	re;

	if (c < -1)
		return ((unsigned char)c);
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		re = c;
	return (re);
}
