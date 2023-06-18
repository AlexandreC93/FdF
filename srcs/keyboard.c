#include "../fdf.h"

static void	ft_reset(t_fdf *env)
{
	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
	if (env->camera->iso)
	{
		env->camera->x_angle = -0.615472907;
		env->camera->y_angle = -0.523599;
		env->camera->z_angle = 0.615472907;
	}
	else
	{
		env->camera->x_angle = -0.523599;
		env->camera->y_angle = -0.261799;
		env->camera->z_angle = 0;
	}
	env->camera->z_height = 1;
	env->camera->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
}

static void	ft_toggle_projection(t_fdf *env)
{
	if (env->camera->iso)
	{
		env->camera->x_angle = -0.523599;
		env->camera->y_angle = -0.261799;
		env->camera->z_angle = 0;
	}
	else
	{
		env->camera->x_angle = -0.615472907;
		env->camera->y_angle = -0.523599;
		env->camera->z_angle = 0.615472907;
	}
	env->camera->iso = !env->camera->iso;
}

static void	ft_mod_height(int code, t_fdf *env)
{
	if (code == MINUS)
		env->camera->z_height += 0.1;
	else if (code == PLUS)
		env->camera->z_height -= 0.1;
	if (env->camera->z_height < 0.1)
		env->camera->z_height = 0.1;
	else if (env->camera->z_height > 10)
		env->camera->z_height = 10;
}

static void	ft_translate(int code, t_fdf *env)
{
	if (code == ARROW_LEFT)
		env->camera->x_offset -= 10;
	else if (code == ARROW_RIGHT)
		env->camera->x_offset += 10;
	else if (code == ARROW_DOWN)
		env->camera->y_offset += 10;
	else if (code == ARROW_UP)
		env->camera->y_offset -= 10;
}

int	ft_key(int code, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (code == ARROW_DOWN || code == ARROW_LEFT || code == ARROW_UP
		|| code == ARROW_RIGHT)
		ft_translate(code, env);
	else if (code == MINUS || code == PLUS)
		ft_mod_height(code, env);
	else if (code == SPACE)
		ft_toggle_projection(env);
	else if (code == KEY_R)
		ft_reset(env);
	else if (code == ESCAPE)
		ft_close(env);
	ft_draw(env->map, env);
	return (0);
}