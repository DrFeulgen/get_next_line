/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:54:07 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 19:07:16 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;

	start = f(lst);
	lst = lst->next;
	tmp = start;
	while (lst)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}
