#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n > 0)
	{
		*ptr++ = (unsigned char)c;
		n--;
	}
	return (str);
}
