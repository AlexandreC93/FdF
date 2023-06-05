#include "fdf.h"
// #include "./get_next_line/get_next_line_bonus.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_fdf	*ft_init(const char *path)
{
	t_fdf	*env;
	char	*title;

	title = ft_strjoin("FdF - ", path);
	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error("malloc error", 1);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error("error connecting to graphics server", 1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (!env->win)
		ft_return_error("error initializing window", 1);
	free(title);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error("error initializing image", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
	env->camera = NULL;
	env->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!env->mouse)
		ft_return_error("error initializing mouse", 1);
	return (env);
}

void test_pxl(void)
{
	void *mlx;
	void *mlx_win;
	int i;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 1200, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	i = 0;
	while (i <= 500)
	{
		my_mlx_pixel_put(&img, 70, i, 0x00FFFF0);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int sort_tab(char **s, t_map map)
{

	printf("[%s]", s[0]);
	return (0);
}


static t_map	*ft_map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		printf("error initializing map");
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int main(int ac, char **av)
{
	char *str;
	char **s;
	t_map *map;
	// char **res;
	int fd;
	// int i;

	// i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		str = "";
	}
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			s = ft_split(str, ' ');
			// printf("%s", s[9]);
			// printf("{%s}\n", s[9]);
			sort_tab(s, *map);
		}
	}
	if (close(fd) == -1)
		printf("error");
	return (0);
}