/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:40:41 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/28 17:35:59 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		j;
	char	*str;
	char	*ss;

	ss = (char *)s;
	str = NULL;
	j = 0;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(ss) + 1))))
			return (NULL);
		while (ss[j])
		{
			str[j] = f(ss[j]);
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
