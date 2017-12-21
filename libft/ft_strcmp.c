/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:16:49 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/27 18:19:26 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				a;
	int				b;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	a = 0;
	b = 0;
	while (t1[a] && t2[b] && t1[a] == t2[b])
	{
		a++;
		b++;
	}
	a = t1[a] - t2[b];
	return (a);
}
