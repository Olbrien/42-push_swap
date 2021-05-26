#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	dest = malloc(sizeof(*dest) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
