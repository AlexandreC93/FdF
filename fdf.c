#include "fdf.h"

static t_fdf *ft_start(const char *name)
{
	t_fdf *env;
	char *title;

	title = ft_strjoin("FdF - ", name);
	env = (t_fdf *)malloc(sizeof(t_fdf));
	if (!env)
		ft_error("malloc error", 1);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_error("error connecting to graphics server", 1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, title);
	if (!env->win)
		ft_error("error initializing window", 1);
	free(title);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_error("error initializing image", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
									   &env->endian);
	env->map = NULL;
	env->camera = NULL;
	env->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!env->mouse)
		ft_error("error initializing mouse", 1);
	return (env);
}

static t_camera *ft_camera_init(t_fdf *env)
{
	t_camera *camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_error("error initializing camera", 1);
	camera->zoom = ft_min(WIDTH / env->map->width / 2,
						  HEIGHT / env->map->height / 2);
	camera->x_angle = -0.615472907;
	camera->y_angle = -0.523599;
	camera->z_angle = 0.615472907;
	camera->z_height = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->iso = 1;
	return (camera);
}

static t_map *ft_map_init(void)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("error initializing map", 1);
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

int main(int ac, char **av)
{
	t_map *map;
	t_point *points;
	t_fdf *env;

	if (ac == 2)
	{
		env = ft_start(av[1]);
		env->map = ft_map_init();
		ft_check(av[1], env->map);
		env->camera = ft_camera_init(env);
		ft_hook_controls(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
	}
	return (0);
}