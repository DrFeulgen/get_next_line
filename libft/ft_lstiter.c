/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:41:37 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 17:52:34 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*elem;

	if (lst && f)
	{
		elem = lst;
		while (lst)
		{
			elem = lst->next;
			f(lst);
			lst = elem;
		}
	}
}
