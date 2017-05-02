/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:13:26 by rbejot            #+#    #+#             */
/*   Updated: 2015/11/30 15:14:02 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fraish;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		fraish = (char *)malloc(ft_strlen(s) * sizeof(*fraish));
		while (s[i] != 0)
		{
			fraish[i] = f(i, s[i]);
			i++;
		}
		return (fraish);
	}
	return (NULL);
}
