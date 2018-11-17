char *ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t size;

	size = ft_strnlen(s2, n);
	if (size != n)
		ft_bzero((void *)(s1 + size), n - size);
	return ((char *)ft_memcpy(s1, s2, size));
}
