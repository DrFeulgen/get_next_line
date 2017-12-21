/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:10:55 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 19:11:44 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int a;

	a = 0;
	if (str[a] == '\0')
		return (1);
	while (str[a])
	{
		while ((str[a] >= 'a' && str[a] <= 'z')
				|| (str[a] >= 'A' && str[a] <= 'Z'))
		{
			a++;
			if (str[a] == '\0')
				return (1);
		}
		return (0);
	}
	return (0);
}
