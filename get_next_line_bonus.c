/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:02:38 by amounach          #+#    #+#             */
/*   Updated: 2022/02/28 16:09:24 by amounach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *buffer)
{
	char	buff[BUFFER_SIZE + 1];
	int		n_b;

	n_b = 1;
	while (!ft_strchr(buffer, '\n') && n_b)
	{
		n_b = read(fd, buff, BUFFER_SIZE);
		if (n_b == -1)
			return (0);
		buff[n_b] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	return (buffer);
}

char	*get_line(char	*buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (0);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rest(char *buffer)
{
	char	*rest;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (0);
	}
	len = ft_strlen(buffer) - i;
	rest = (char *)malloc(sizeof(char) * len + 1);
	if (!rest)
		return (0);
	i++;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[100000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = get_line(buffer[fd]);
	buffer[fd] = ft_rest(buffer[fd]);
	return (line);
}

int		main(void)
{
	char *line;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		printf("%s", line);
	}
}

