/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/02/12 14:31:55 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		addmal(char *save)
{
	char *tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1))))
		return (0);
	ft_strcpy(tmp, save);
	save = NULL;
	if (!(save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return(0);
	ft_strcpy(save, tmp);
	return (1);
}

int		makeline(int ret, char *save, char **line)
{
	int x;
	int a;

	x = 0;
	a = 0;
	if (!(*line = (char *)malloc(sizeof(char) * ret)))
		return (-1);
	if (ret != 0 || ft_strlen(save) != 0)
	{
		while (save[x] != '\n' && save[x])
		{
			line[a][x] = save[x];
			x++;
		}
		line[a][x] = '\0';
		x++;
		a = 0;
		if (save[0] == '\n')
		{
			//while (save[i])
			//	save[a++] = save[x++];
			save[0] = '\0';
			return (2);
		}
		while (save[x])
		{
			save[a] = save[x];
			a++;
			x++;
		}
		save[a] = '\0';
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char *save;
	int			ret;

	//ret = 1;
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (!save)
		save = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(addmal(save)))
			return(-1);
		if (!(save = ft_strjoin(save, *line)))
			return (-1);
		if (ft_memchr(*line, '\n', BUFF_SIZE) || ft_strlen(*line) < BUFF_SIZE)
			break;
	}
	if ((makeline(ret, save, &(*line)) == 2))
		return (1);
	if (ret == 0)
		return (0);
	//ft_putstr("\nerg\n");
	return (1);
}

   int		main(int ac, char **av)
   {
   char *line;
   int fd;
   int ret;
   fd = open(av[1], O_RDONLY);
   if (ac == 2)
   {
   while ((ret = get_next_line(fd, &line)) > 0)
   {
   ft_putstr(line);
   ft_putnbr(ret);
   ft_putstr("\n");
   }
   }
   close(fd);
   ft_putstr("outsuccess");
   return (0);
   }
