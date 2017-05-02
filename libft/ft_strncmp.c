/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:50:15 by rbejot            #+#    #+#             */
/*   Updated: 2015/11/30 18:21:33 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while ((*t1 || *t2) && n--)
	{
		if (*t1 < *t2)
			return (*t1 - *t2);
		if (*t1 > *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
	}
	return (0);
}
