#include "libft.h"

char    *ft_get_txt(int fd)
{
    char *line;
    int res;

    while ((res = get_next_line(fd, &line)) > 0)
        return (line);
    return (NULL);
}