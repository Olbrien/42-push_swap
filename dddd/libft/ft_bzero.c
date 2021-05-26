#include "libft.h"

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
