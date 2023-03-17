#include "get_next_line4.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join;
	int	i;
	int	j;

	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		join[i] = str2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_trim(char *line)
{
	char	*stash;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (0);
	i++;
	if (!line[i])
		return (0);
	stash = ft_strdup(line + i);
	line[i] = '\0';
	return (stash);
}

char	*ft_get(int fd, char *buffer, char *stash)
{
	char	*temp;
	int	bread;

	bread = 1;
	while (bread)
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread < 0)
			return (0);
		if (bread == 0)
			break;
		buffer[bread] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = ft_strdup(stash);
		free(stash);
		stash = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_check_char(buffer))
			break;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_get(fd, buffer, stash);
	free(buffer);
	if (!line)
	{
		free (stash);
		return (0);
	}
	stash = ft_trim(line);
	return (line);
}
/* 
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
} */