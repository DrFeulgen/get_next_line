/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/02/28 13:40:49 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		makeline2(int x, char *save)
{
	int a;

	a = 0;
	{
		if (save[x] == '\0')
		{
			save[0] = '\0';
			return (2);
		}
		x++;
		if (save[0] == '\n')
		{
			while (save[a + 1])
			{
				save[a] = save[a + 1];
				a++;
			}
			save[a] = '\0';
			return (2);
		}
		while (save[x])
			save[a++] = save[x++];
		save[a] = '\0';
	}
	return (2);
}

int		makeline(int ret, char *save, char **line)
{
	int x;
	int a;

	x = 0;
	a = 0;
	if (!(*line = (char *)malloc(sizeof(char) * ft_strlen(save))))
		return (-1);
	if (ret != 0 || ft_strlen(save) != 0)
	{
		while (save[x] != '\n' && save[x])
		{
			line[a][x] = save[x];
			x++;
		}
		line[a][x] = '\0';
		makeline2(x, save);
	}
	return (2);
}

int		get_next_line(int const fd, char **line)
{
	static char	*save;
	char		*savetmp;
	char		buffer[BUFF_SIZE];
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	if (!save)
		save = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		savetmp = save;
		if (!(save = ft_strnjoin(savetmp, buffer, ret)))
			return (-1);
		free(savetmp);
		savetmp = NULL;
		if (ft_memchr(save, '\n', ft_strlen(save)) || ret < BUFF_SIZE)
			break ;
	}
	if (ret == 0 && save[0] == '\0')
		return (0);
	if ((makeline(ret, save, line) == 2))
		return (1);
	return (0);
}
