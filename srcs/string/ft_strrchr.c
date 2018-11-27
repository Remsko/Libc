#include "string_42.h"

char *ft_strrchr(const char *s, int c)
{
	const char *found;
	const char *ptr;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while ((ptr = ft_strchr(s, c)) != NULL)
	{
		found = ptr;
		s = ptr + 1;
	}
	return ((char *)found);
}
