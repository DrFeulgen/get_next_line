/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 13:37:51 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/28 17:50:24 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (ft_strlen((char *)to_find) == 0)
		return ((char *)str);
	while (str[a])
	{
		b = 0;
		while (str[a + b] == to_find[b])
		{
			if (to_find[b + 1] == '\0')
				return ((char *)str + a);
			b++;
		}
		a++;
	}
	return (0);
}
