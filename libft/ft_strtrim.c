/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:31:01 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/28 15:11:54 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		z;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	z = ft_strlen((char *)s) - 1;
	while (z > i && (s[z] == ' ' || s[z] == ',' ||
				s[z] == '\n' || s[z] == '\t'))
		z--;
	if (z < i)
		return (str = ft_strdup(""));
	return (str = ft_strsub((char *)s, i, z - i + 1));
}
