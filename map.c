#include "fdf.h"

int	ft_get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	height = 0;
	while (get_next_line(fd, &line) >= 0 && *line != '\0')
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
	return (height);
}

int	ft_get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	width = 0;
	get_next_line(fd, &line);
	if (*line == '\0')
		ft_return_error("invalid map (empty)", 0);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
	return (width);
}
