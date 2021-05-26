#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char			*arra;
	size_t			i;
	unsigned int	total;

	total = nitems * size;
	arra = malloc(nitems * size);
	if (arra == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		arra[i] = 0;
		total--;
		i++;
	}
	return ((void *)arra);
}
