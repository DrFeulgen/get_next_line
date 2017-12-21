/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:48:39 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 11:06:38 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *scr)
{
	int		a;
	int		s;
	char	*str;

	s = 0;
	while (scr[s])
		s++;
	if (!(str = (char*)malloc(sizeof(char) * (s + 1))))
		return (NULL);
	a = 0;
	while (a < s)
	{
		str[a] = scr[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
