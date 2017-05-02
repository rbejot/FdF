/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:53:58 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/21 17:02:14 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			collect_x(char *line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) != 1 && line[j] != ' ' && line[j] != '-' &&
				line[j] != '+')
			usage(2);
		j++;
	}
	j = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) == 1 && (ft_isdigit(line[j - 1]) != 1 ||
					j == 0))
			i++;
		else if (ft_isdigit(line[j + 1]) == 1 && ft_isdigit(line[j]) == 1
				&& ft_isdigit(line[j - 1]) != 1)
			i = i - 1;
		j++;
	}
	return (i);
}

int			check_x(char *line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) == 1 && (ft_isdigit(line[j - 1]) != 1 ||
					j == 0))
			i++;
		else if (ft_isdigit(line[j + 1]) == 1 && ft_isdigit(line[j]) == 1
				&& (ft_isdigit(line[j - 1]) != 1 || j == 0))
			i = i - 1;
		j++;
	}
	return (i);
}

t_liste		*list_new(char *line)
{
	t_liste	*new;
	int		i;
	int		j;

	if ((new = (t_liste*)ft_memalloc(sizeof(t_liste))) == NULL)
		exit(0);
	new->length = collect_x(line);
	new->tab = (int*)ft_memalloc(sizeof(int) * new->length);
	new->next = NULL;
	j = 0;
	i = 0;
	while (line[j] != '\0')
	{
		if ((ft_isdigit(line[j]) == 1 || line[j] == '-') && (j == 0 ||
					line[j - 1] == ' '))
		{
			new->tab[i] = ft_atoi(&line[j]);
			i++;
		}
		j++;
	}
	return (new);
}

void		list_add(t_liste **begin_list, char *line)
{
	t_liste	*tmp;

	tmp = *begin_list;
	if (!tmp)
		*begin_list = list_new(line);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new(line);
	}
}

t_env		read_fdf(char **av, t_env *env)
{
	int		*i;

	if ((env->begin_list = (t_liste*)ft_memalloc(sizeof(t_liste))) == NULL)
		exit(0);
	env->begin_list = NULL;
	env->fd = open(av[1], O_RDONLY);
	if (env->fd == -1)
		usage(4);
	env->size = 0;
	i = (int*)ft_memalloc(sizeof(int) * 10000);
	while (get_next_line(env->fd, &env->line) != 0)
	{
		i[env->size] = check_x(env->line);
		if ((i[env->size] != i[env->size - 1]) && env->size != 0)
			usage(5);
		else
			list_add(&env->begin_list, env->line);
		env->size++;
	}
	if (env->size == 0)
		usage(3);
	return (*env);
}
