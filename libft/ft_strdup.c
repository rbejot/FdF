/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:57:33 by rbejot            #+#    #+#             */
/*   Updated: 2015/11/25 11:13:18 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*s2;

	i = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	return (ft_strcpy(s2, s));
}
