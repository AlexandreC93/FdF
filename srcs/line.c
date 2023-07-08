/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcadinot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:57:49 by lcadinot          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:52 by lcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	ft_color(int x, t_point s, t_point e, float fctr)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= fctr;
	g *= fctr;
	b *= fctr;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_draw_line_loop(t_point s, t_point e, float grad, t_fdf *env)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->steep)
		{
			ft_pixel(env, ft_ipart(inter_y), x,
				ft_color(x, s, e, ft_rfpart(inter_y)));
			ft_pixel(env, ft_ipart(inter_y) + 1, x,
				ft_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			ft_pixel(env, x, ft_ipart(inter_y),
				ft_color(x, s, e, ft_rfpart(inter_y)));
			ft_pixel(env, x, ft_ipart(inter_y) + 1,
				ft_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += grad;
		x++;
	}
}

void	ft_draw_line(t_point s, t_point e, t_fdf *env)
{
	float	dy;
	float	dx;
	float	grad;

	env->steep = ft_abs(e.y - s.y) > ft_abs(e.x - s.x);
	if (env->steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	grad = dy / dx;
	if (dx == 0.0f)
		grad = 1.f;
	ft_draw_line_loop(s, e, grad, env);
}
