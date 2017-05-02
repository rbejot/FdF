/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:09:19 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/20 20:01:01 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_rotate(int keycode, t_env *env)
{
	if (keycode == UP)
	{
		env->alpha = env->alpha + 0.1;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == DOWN)
	{
		env->alpha = env->alpha - 0.1;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == RIGHT)
	{
		env->omega = env->omega - 0.1;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == LEFT)
	{
		env->omega = env->omega + 0.1;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	return (0);
}

int	key_zoom(int keycode, t_env *env)
{
	if (keycode == X)
	{
		env->fac = env->fac + 4;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == Z)
	{
		env->fac = env->fac - 4;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	return (0);
}

int	key_move(int keycode, t_env *env)
{
	if (keycode == W)
	{
		env->origin_y = env->origin_y - 10;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == S)
	{
		env->origin_y = env->origin_y + 10;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == A)
	{
		env->origin_x = env->origin_x - 10;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == D)
	{
		env->origin_x = env->origin_x + 10;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	return (0);
}

int	key_color(int keycode, t_env *env)
{
	if (keycode == N1)
	{
		env->color = 0x00F02323;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == N2)
	{
		env->color = 0x00FF007F;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == N3)
	{
		env->color = 0x0000FFFF;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == N4)
	{
		env->color = 0x00FFFFCC;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	return (0);
}

int	key_height(int keycode, t_env *env)
{
	if (keycode == C)
	{
		env->up = env->up + 0.2;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == V)
	{
		env->up = env->up - 0.2;
		mlx_clear_window(env->mlx, env->win);
		rotate_map(env);
	}
	else if (keycode == RETURN)
	{
		env->origin_x = env->origin_x + 10;
		mlx_clear_window(env->mlx, env->win);
		init_env(env);
		rotate_map(env);
	}
	return (0);
}
