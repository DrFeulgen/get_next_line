/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:14:44 by bbataini          #+#    #+#             */
/*   Updated: 2017/11/30 16:52:58 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int minus;

	nbr = 0;
	i = 0;
	minus = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f'
	|| str[i] == '\v' || str[i] == ' ' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - 48;
		i++;
	}
	return (nbr * minus);
}
