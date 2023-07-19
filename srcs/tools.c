#include "../fdf.h"

int check_map(const char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        ft_error("open error", 1);
    get_next_line(fd, &line);
    if (*line == '\0')
    {
        if (close(fd) == -1)
            ft_error("close error", 1);
        free(line);
        ft_error("invalid map (empty)", 0);
    }
    free(line);
    return (1);
}