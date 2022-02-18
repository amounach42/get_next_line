#include <unistd.h>
#include <stdlib.h>

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
