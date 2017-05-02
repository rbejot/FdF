/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:54:08 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/20 18:35:04 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector		ft_acdir(t_vector vect, t_env *env)
{
	vect.x = ft_isneg(env->i.x - env->j.x) * -1;
	vect.y = ft_isneg(env->i.y - env->j.y) * -1;
	return (vect);
}

t_vector		ft_acvect(t_env *env)
{
	t_vector	vect;
	float		xsum;
	float		ysum;

	ysum = (env->j.y - env->i.y);
	xsum = (env->j.x - env->i.x);
	if (ysum != 0 && xsum != 0)
		vect.inter = xsum / ysum;
	else
		vect.inter = 1;
	vect = ft_acdir(vect, env);
	return (vect);
}

int				ft_wrline(t_env *env)
{
	t_vector	vect;
	float		nx;
	float		ny;

	vect = ft_acvect(env);
	nx = 0;
	ny = 0;
	mlx_pixel_put(env->mlx, env->win, env->i.x, env->i.y, env->color);
	mlx_pixel_put(env->mlx, env->win, env->j.x, env->j.y, env->color);
	while ((nx + env->i.x != env->j.x || ny + env->i.y != env->j.y))
	{
		if (nx == 0 || ny == 0)
		{
			nx += vect.x;
			ny += vect.y;
		}
		else if (ft_revneg(nx) / ft_revneg(ny) < ft_revneg(vect.inter))
			nx += vect.x;
		else
			ny += vect.y;
		mlx_pixel_put(env->mlx, env->win, nx + env->i.x, ny + env->i.y,
				env->color);
	}
	return (0);
}

t_env			next_point(t_env *env)
{
	if (env->index == (env->tmp->length - 1) ||
			(env->index == env->border && env->border != 0))
	{
		env->j.x = env->e[env->index].new_x;
		env->j.y = env->e[env->index].new_y;
		env->border = env->index + env->tmp->length;
	}
	else if (env->index != (env->tmp->length - 1))
	{
		env->j.x = env->e[env->index + 1].new_x;
		env->j.y = env->e[env->index + 1].new_y;
	}
	return (*env);
}

void			send_points(t_env *env)
{
	env->index = 0;
	env->border = 0;
	while (env->index < env->nb_points)
	{
		env->i.x = env->e[env->index].new_x;
		env->i.y = env->e[env->index].new_y;
		next_point(env);
		ft_wrline(env);
		if (env->index < (env->nb_points - env->tmp->length))
		{
			env->j.x = env->e[env->index + env->tmp->length].new_x;
			env->j.y = env->e[env->index + env->tmp->length].new_y;
		}
		ft_wrline(env);
		env->index++;
	}
}
