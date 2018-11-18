#include <stdlib.h>
#include "memory_42.h"
#include "string_42.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_strnlen(s, n);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	new[len] = '\0';
	return ((char *)ft_memcpy((void *)new, s, len));
}
