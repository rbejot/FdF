/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:53:19 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/21 16:52:05 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_instruction(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 3, 1, 0x00FFFFFF, "Close [Esc]");
	mlx_string_put(env->mlx, env->win, 135, 1, 0x00FFFFFF, "Reset [RETURN]");
	mlx_string_put(env->mlx, env->win, 3, 25, 0x00FFFFFF,
			"Rotate USE KEYBOARD ARROW");
	mlx_string_put(env->mlx, env->win, 3, 45, 0x00FFFFFF, "Move   USE W-A-S-D");
	mlx_string_put(env->mlx, env->win, 3, 70, 0x00FFFFFF, "Zoom + [X]");
	mlx_string_put(env->mlx, env->win, 120, 70, 0x00FFFFFF, "Zoom - [Z]");
	mlx_string_put(env->mlx, env->win, 3, 90, 0x00FFFFFF, "Height + [C]");
	mlx_string_put(env->mlx, env->win, 130, 90, 0x00FFFFFF, "Height - [V]");
	mlx_string_put(env->mlx, env->win, 700, 1, 0x00FFFFFF,
			ft_itoa(env->nb_points));
	mlx_string_put(env->mlx, env->win, 500, 1, 0x00FFFFFF, "Nb of Points :");
	mlx_string_put(env->mlx, env->win, 0, 130, 0x00F02323, "[1]");
	mlx_string_put(env->mlx, env->win, 50, 130, 0x00FF007F, "[2]");
	mlx_string_put(env->mlx, env->win, 100, 130, 0x0000FFFF, "[3]");
	mlx_string_put(env->mlx, env->win, 150, 130, 0x00FFFFCC, "[4]");
}

int		key_press(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit(1);
	key_rotate(keycode, env);
	key_zoom(keycode, env);
	key_move(keycode, env);
	key_color(keycode, env);
	key_height(keycode, env);
	print_instruction(env);
	return (0);
}

void	usage(int i)
{
	if (i == 1)
	{
		ft_putendl("ERROR : INVALID NUMBER OF ARGUMENTS");
		exit(0);
	}
	if (i == 2)
	{
		ft_putendl("ERROR : THERE IS A NON NUMERICAL ENTRY IN YOUR MAP.");
		exit(0);
	}
	else if (i == 3)
	{
		ft_putendl("ERROR : EMPTY FILE");
		exit(0);
	}
	else if (i == 4)
	{
		ft_putendl("ERROR : THE FILE IS NOT VALID");
		exit(0);
	}
	else if (i == 5)
	{
		ft_putendl("ERROR : YOUR MAP IS NOT A PARALLELOGRAM");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_env *env;

	if (ac != 2)
		usage(1);
	env = (t_env*)ft_memalloc(sizeof(t_env));
	read_fdf(av, env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1000, 1000, av[1]);
	stock_points(env);
	print_instruction(env);
	init_env(env);
	rotate_map(env);
	mlx_key_hook(env->win, key_press, env);
	mlx_loop(env->mlx);
	return (0);
}
