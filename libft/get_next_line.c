/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:12:32 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/21 16:54:49 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_join(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

static void		ft_gnl(char **tp, char ***line)
{
	if (!ft_strchr(*tp, '\n'))
	{
		**line = ft_strdup(*tp);
		ft_strdel(tp);
	}
	else
	{
		**line = ft_strsub(*tp, 0, ft_strchr(*tp, '\n') - *tp);
		*tp = ft_strsub(*tp, ((ft_strchr(*tp, '\n') - *tp) + 1),
				ft_strlen(*tp));
	}
}

int				get_next_line(int const fd, char **line)
{
	static char	*tp;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (tp == NULL)
		tp = ft_memalloc(1);
	while (!ft_strchr(tp, '\n') && (ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tp = ft_join(tp, buf);
	}
	if (ret == -1)
		exit(-1);
	ft_gnl(&tp, &line);
	if (!tp && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
