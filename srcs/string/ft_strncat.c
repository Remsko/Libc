char *ft_strncat(char *s1, const char *s2, size_t n)
{
	char *s;
	size_t ss;

	s = s1;
	s1 += strnlen(s2, n);
	ss = strnlen(s2, n);
	s1[ss] = '\0';
	ft_memcpy(s1, s2, ss);
	return (s);
}
