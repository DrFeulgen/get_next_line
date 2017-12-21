/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:04:00 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 19:18:59 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int a;

	a = 0;
	if (str[a] >= 'a' && str[a] <= 'z')
		str[a] = str[a] - 32;
	while (str[a])
	{
		if ((str[a - 1] == ' ' || str[a - 1] == '+' || str[a - 1] == '-' ||
					str[a - 1] == '\n') && (str[a] >= 'a' && str[a] <= 'z'))
		{
			if (str[a] == '\0')
				return (str);
			str[a] = str[a] - 32;
		}
		if ((str[a] >= 'A' && str[a] <= 'Z') && (
					((str[a - 1] >= 'a' && str[a - 1] <= 'z')) ||
					(str[a - 1] >= 'A' && str[a - 1] <= 'Z')))
		{
			str[a] = str[a] + 32;
		}
		a++;
		if (str[a] == '\0')
			return (str);
	}
	return (str);
}
