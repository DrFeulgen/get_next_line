/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:36:07 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 17:27:11 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *str;

	if (!(str = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		if (!(str->content = (void *)malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(str->content, content, content_size);
		str->content_size = content_size;
	}
	str->next = NULL;
	return (str);
}
