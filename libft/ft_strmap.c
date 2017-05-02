/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:12:48 by rbejot            #+#    #+#             */
/*   Updated: 2015/12/01 11:21:43 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraish;
	int		i;

	if (!s || !f)
		return (NULL);
	fraish = (char *)malloc(sizeof(*fraish) * (ft_strlen(s) + 1));
	if (fraish)
	{
		i = 0;
		while (s[i] != '\0')
		{
			fraish[i] = f(s[i]);
			i++;
		}
		fraish[i] = '\0';
	}
	return (fraish);
}
