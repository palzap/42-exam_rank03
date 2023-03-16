#include "get_next_line2.h"

int	ft_check_newline(char *str)
{
    int i;

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
    char *dup;
    int i;

    i = 0;
    dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    while (str[i])
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char *ft_join(char *str1, char *str2)
{
    char    *join;
    int i;
    int j;

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

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_get_all(int fd, char *buffer, char *stash)
{
    char    *temp;
    int bread;

    bread = 1;
    while (bread)
    {
        bread = read(fd, buffer, BUFFER_SIZE);
        if (bread < 0)
            return (0);
        if (bread == 0)
            break ;
        buffer[bread] = '\0';
        if (!stash)
            stash = ft_strdup("");
        temp = ft_strdup(stash);
        free(stash);
        stash = ft_join(temp, buffer);
        free(temp);
        if (ft_check_newline(buffer))
            break ;
    }
    return (stash);
}

char    *ft_trim(char *line)
{
    char *stash;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] == '\0')
        return (0);
    i++;
    stash = (char *)malloc(sizeof(char) * (ft_strlen(line + i) + 1));
    k = i;
    while (line[i])
    {
        stash[j] = line[i];
        j++;
        i++;
    }
    stash[j] = '\0';
    if (stash[0] == '\0')
    {
        free(stash);
        stash = 0;
    }
    line[k] = '\0';
    return (stash);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    static char *stash;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (0);
    line = ft_get_all(fd, buffer, stash);
    free(buffer);
    if (!line)
    {
        free(stash);
        stash = 0;
        return (stash);
    }
    stash = ft_trim(line);
    return(line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
    char	*line;

	(void)argc;
    fd = open(argv[1], O_RDONLY);
	line = ft_strdup("");
    while (line)
    {
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
    }
	free(line);
	return (0);
}