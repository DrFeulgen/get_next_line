/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/02/27 14:34:20 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		makeline(int ret, char *save, char **line)
{
	int x;
	int a;
//		ft_putstr("\nmakeline : ");
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
		if (save[x] == '\0')
		{
			save[0] = '\0';
			return (2);
		}
		x++;
		a = 0;
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
//		if (save[0] == '\0')
//			return (1);
		while (save[x])
			save[a++] = save[x++];
		save[a] = '\0';
	}
	return (2);
}
/*
int		makeline2(char *save, char **line)
{
	int x;
	int a;

//		ft_putstr("\nmakeline2 : ");
	x = 0;
	a = 0;
	if (!(*line = (char *)malloc(sizeof(char) * ft_strlen(save))))
		return (-1);
	if (save[0] == '\n')
	{
		line[a][x] = '\0';
		while (save[x + 1])
		{
			save[x] = save[x + 1];
			x++;
		}
		save[x] = '\0';
	}
	while (save[x] != '\n' && save[x])
	{
		line[a][x] = save[x];
		x++;
	}
	if (save[x] == '\0')
		return (2);
	line[a][x] = '\0';
	x++;
	while (save[x])
		save[a++] = save[x++];
	save[a] = '\0';
	return (2);
}*/

int		get_next_line(int const fd, char **line)
{
	static char *save;
	//char *str;
	char *savetmp;
	char buffer[BUFF_SIZE];
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (!save)
		save = ft_strnew(BUFF_SIZE);
/*	if (ft_memchr(save, '\n', ft_strlen(save) ))
	{
		if (makeline2(save, line) == 2)
			return (1);
	}*/
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
	//			ft_putstr("\nread : ");
	//ft_putnbr(ret);
	//			ft_putstr(buffer);
		savetmp = save;
		if (!(save = ft_strnjoin(savetmp, buffer, ret)))
			return (-1);
		//savetmp = NULL;
		free(savetmp);
		savetmp = NULL;
		if (ft_memchr(save, '\n', ft_strlen(save)) || ret < BUFF_SIZE)
			break;
	}
	if (ret == 0 && save[0] == '\0')
		return (0);
		if ((makeline(ret, save, line) == 2))
			return (1);
	return (0);
}
/*
int		main(int ac, char **av)
  {
  char *line;
  int fd;
  int ret;
  int i;
  fd = open(av[1], O_RDONLY);
  if (ac == 2)
  i = 0;
  {
  while ((ret = get_next_line(fd, &line)) > 0 && i < 505)
  {
  ft_putstr(line);
  ft_putnbr(ret);
  ft_putstr("\n");
  i++;
  }
  }
  close(fd);
  ft_putstr("outsuccess");
  return (0);
  }*/
