/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:31:39 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/04 17:50:44 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	if (*alst && alst && del)
	{
		current = *alst;
		while (current)
		{
			del(current->content, current->content_size);
			tmp = current->next;
			free(current);
			current = NULL;
			current = tmp;
		}
		*alst = NULL;
		alst = NULL;
	}
}
