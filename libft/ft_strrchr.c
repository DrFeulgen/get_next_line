/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:22:10 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/29 18:38:23 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	while (len > 0 && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char *)s + len);
	return (NULL);
}
