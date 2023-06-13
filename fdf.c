#include "fdf.h"

void *sort_tab(char **s, t_map map)
{

	// printf("[%s]", s[9]);
	return (0);
}

void fill_tab(t_point *points, char **av, t_map *map)
{
	char *line;
	int gnl;
	char **buffer;
	int fd;
	int	i;

	gnl = 1;
	// printf("%d", points->nb_points);
	buffer = malloc(sizeof(char*) * points->nb_points + 2);
	points->tab = malloc(sizeof(int) * points->nb_points + 1);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		printf("{%s}\n", line);
		buffer = ft_split(line, ' ');
		printf("%s", buffer[0]);
		while (i < points->nb_points)
		{
			points->tab[i] = ft_atoi(buffer[i]);
			i++;
			// printf("[%d]", points->tab[i]);
		}
	}
}

int main(int ac, char **av)
{
	t_map *map;
	t_point *points;
	t_fdf *fdf;

	int i;

	map = (t_map *)malloc(sizeof(t_map));
	points = (t_point *)malloc(sizeof(t_point));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 800, 600, "HELLO");
	map->height = ft_height(av[1]);
	// printf("%d\n", map->height);
	map->width = ft_width(av[1]);
	// printf("%d\n", map->width);
	points->nb_points = map->width * map->height;

	if (ac > 1)
		fill_tab(points, av, map);
	i = 0;
	while (i < points->nb_points - 1)
	{
	}
	mlx_loop(fdf->mlx);
	return (0);
}