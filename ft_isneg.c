/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isneg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 21:54:24 by rbejot            #+#    #+#             */
/*   Updated: 2016/04/20 17:05:52 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_isneg(float i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	else
		return (0);
}

float	ft_revneg(float i)
{
	if (i < 0)
		i = i * -1;
	return (i);
}
