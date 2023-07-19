/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:49 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:52 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_close(void *params)
{
	t_fdf	*env;
	int		x;
	int		y;
	int		j;

	env = (t_fdf *)params;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	j = 0;
	y = -1;
	while (++y < env->map->height)
	{
		x = 0;
		while (x++ < env->map->width)
		{
			if (!env->map->array[y][x - 1])
				break;
			free(env->map->array[y][x]);
			printf("%d", j++);
		}
		free(env->map->array[y]);
	}
	free(env->map->array);
	free(env->map);
	free(env->camera);
	free(env->mouse);
	free(env->mlx);
	free(env);
	exit(0);
}

void	ft_hook_controls(t_fdf *env)
{
	mlx_hook(env->win, 2, 1L << 0, ft_key, env);
	mlx_hook(env->win, 4, 1L << 2, ft_mouse_down, env);
	mlx_hook(env->win, 5, 1L << 3, ft_mouse_up, env);
	mlx_hook(env->win, 6, 1L << 13, ft_mouse_move, env);
	mlx_hook(env->win, 17, 1L << 17 | 1L << 19, ft_close, env);
}

double	ft_reset_angles(double angle)
{
	if (angle >= M_PI)
		return (-2 * M_PI - angle);
	else if (angle <= -M_PI)
		return (2 * M_PI + angle);
	return (angle);
}
