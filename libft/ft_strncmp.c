/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 12:36:47 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/27 18:34:07 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	unsigned int	b;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	a = 0;
	b = 0;
	if (n == 0)
		return (0);
	n--;
	while (t1[a] == t2[b] && a < n && t1[a] && t2[a])
	{
		a++;
		b++;
	}
	a = t1[a] - t2[b];
	return (a);
}
