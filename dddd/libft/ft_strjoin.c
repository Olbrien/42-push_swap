#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		len;
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (!s1)
		return (NULL);
	if (!s2 && s1)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(len + 1 * sizeof(string));
	if (string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
		string[i++] = s2[b++];
	string[i] = '\0';
	return (string);
}
