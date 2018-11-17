char *ft_strcat(char *dest, const char *src)
{
	return (ft_strcpy(dest + ft_strlen(dest), src));
}
