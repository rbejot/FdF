/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:45:07 by rbejot            #+#    #+#             */
/*   Updated: 2015/12/01 11:08:17 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_word(char const *s, char c)
{
	int		cnt;
	int		is_word;

	cnt = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			cnt++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (cnt);
}

static int	ft_word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			nb_word;
	int			i;

	if (s)
	{
		i = 0;
		nb_word = ft_nb_word(s, c);
		tab = (char **)malloc(sizeof(char *) * (nb_word + 1));
		if (!tab)
			return (NULL);
		while (nb_word--)
		{
			while (*s == c && *s != '\0')
				s++;
			tab[i] = ft_strsub(s, 0, ft_word_len(s, c));
			if (tab[i] == NULL)
				return (NULL);
			s = s + ft_word_len(s, c);
			i++;
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
