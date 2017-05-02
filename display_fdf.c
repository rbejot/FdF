/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:53:47 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/20 18:46:36 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	rotate_map(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_points)
	{
		env->e[i].new_x = env->origin_x + env->fac * (cos(env->omega) *
				env->e[i].x + sin(env->omega) * env->e[i].y);
		if (env->e[i].z != 0)
		{
			env->e[i].new_y = env->origin_y + env->fac * (sin(env->alpha) *
					(sin(env->omega) * env->e[i].x - cos(env->omega) *
					env->e[i].y) + env->up * cos(env->alpha) * env->e[i].z);
		}
		else
		{
			env->e[i].new_y = env->origin_y + env->fac * (sin(env->alpha) *
					(sin(env->omega) * env->e[i].x - cos(env->omega) *
					env->e[i].y) + cos(env->alpha) * env->e[i].z);
		}
		i++;
	}
	send_points(env);
	return (*env);
}

t_env	init_env(t_env *env)
{
	env->alpha = 3.8;
	env->omega = 7.2;
	env->up = 0;
	if (env->nb_points > 1000)
	{
		env->origin_x = 50;
		env->origin_y = 700;
		env->fac = 6;
	}
	else if (env->nb_points >= 4 && env->nb_points <= 100)
	{
		env->origin_y = 500;
		env->origin_x = 250;
		env->fac = 20;
	}
	else
	{
		env->origin_y = 500;
		env->origin_x = 100;
		env->fac = 20;
	}
	env->color = 0x00FFFFFF;
	return (*env);
}

t_env	stock_points(t_env *env)
{
	env->y = 0;
	env->c = 0;
	env->tmp = env->begin_list;
	env->len = env->tmp->length;
	env->e = (t_coor*)ft_memalloc(sizeof(t_coor) *
			(env->size * env->tmp->length));
	while (env->tmp)
	{
		env->x = 0;
		while (env->x < env->tmp->length)
		{
			env->e[env->c].x = env->x;
			env->e[env->c].y = env->y;
			env->e[env->c].z = env->tmp->tab[env->x];
			env->c++;
			env->x++;
		}
		env->y++;
		env->tmp = env->tmp->next;
	}
	env->nb_points = env->y * env->len;
	env->tmp = env->begin_list;
	return (*env);
}
