#include "libft.h"

int	ft_toupper(int c)
{
	int	re;

	if (c < -1)
		return ((unsigned char)c);
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		re = c;
	return (re);
}
