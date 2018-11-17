char *ft_strcpy(char *dest, const char *src)
{
	return ((char *)ft_memcpy(dest, src, ft_strlen(src) + 1));
}
