/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:28:45 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/23 16:29:29 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	int					a;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	a = 0;
	while (n != 0)
	{
		if (t1[a] != t2[a])
			return (t1[a] - t2[a]);
		if (n != 0)
		{
			a++;
			n--;
		}
	}
	return (0);
}
