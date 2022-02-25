#include <unistd.h>
#include <stdlib.h>

char	*ft_read(int fd, char *buffer)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		buff[bytes_read] = '\0';
		buffer_ft_strjoin(buffer, bytes_read);
	}
	return (buffer)
}

char	*get_line(char	*buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);

	while (buffer[i] != '\n' && buffer[i] != '\0') 
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	line[i] = '\0';
	return (line);

}



char	*get_next_line(int fd)
{
		
}
