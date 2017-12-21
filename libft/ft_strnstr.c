/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:11:09 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/27 18:11:58 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	b = 0;
	while (str[a] && a < n)
	{
		if (str[a] == to_find[b])
		{
			while (str[a] == to_find[b] && a < n && to_find[b])
			{
				b++;
				a++;
			}
		}
		if (to_find[b] == '\0')
			return ((char *)str + a - b);
		a = a - b;
		b = 0;
		a++;
	}
	return (NULL);
}
