
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	int		str_len;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_str_len(s2);
   	i = 0;
	j = 0;
	str = (char *) malloc((str_len + 1) * sizeof(char));
		if (!str) 
			return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
