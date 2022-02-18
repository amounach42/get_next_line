
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		length;
	char	*str;

	i = -1;
	length = strlen(s) + 1;
	if (!s)
		return (NULL);
	if (length < (int)start)
		return (strdup(""));
	if (len > (length - start))
		len = length - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < (int)len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);

}
