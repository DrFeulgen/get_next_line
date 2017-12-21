/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:17:20 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 12:14:35 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	tmp[n];

	if (n < 134217728)
	{
		ft_memcpy(tmp, (unsigned char *)src, n);
		ft_memcpy((unsigned char *)dest, tmp, n);
		return ((unsigned char *)dest);
	}
	return (NULL);
}
