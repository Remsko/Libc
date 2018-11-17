#include <stdlib.h>

char *ft_strdup(const char *s)
{
	void	*new;
	size_t	len;

	len = ft_strlen(s) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s, len));
}
