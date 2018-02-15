/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/02/15 15:21:49 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		addmal(int ret, char *save)
{
	char *tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1))))
		return (0);
	ft_strcpy(tmp, save);
	save = NULL;
	if (!(save = ft_strnew(ft_strlen(tmp) + ret)))
		return(0);
	ft_strcpy(save, tmp);
	return (1);
}

int		makeline(int ret, char *save, char **line)
{
	int x;
	int a;
	ft_putstr("\nmakeline : ");
	x = 0;
	a = 0;
	//ft_putstr("\nmakeline\n");
	//ft_putstr(*line);
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
				save[0] = '\0';
				//while (save[x])
				//	save[a++] = save[x++];
				return (1);
			}
		if (save[0] == '\0')
		{
			//	save[a++] = save[x++];
			save[0] = '\0';
			return (1);
		}
		while (save[x])
		{
			save[a] = save[x];
			a++;
			x++;
		}
		save[a] = '\0';
	}
	return (2);
}

int		makeline2(char *save, char **line)
{
	int x;
	int a;

	ft_putstr("\nmakeline2 : ");
	x = 0;
	a = 0;

	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (save[0] == '\n')
	{
		line[a][x] = '\0';
		while (save[x + 1])
		{
			save[x] = save[x + 1];
			x++;
		}
	}
//	ft_putstr(" line : ");
//	ft_putstr(*line);
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
	{
		save[a++] = save[x++];


	}
	//ft_putstr("\n");
	//ft_putstr(save);
	save[a] = '\0';
//	ft_putstr("\n");
//	ft_putstr(save);
	return (2);
}

//char	remallocline(int ret, char **line)
//{



int		get_next_line(int const fd, char **line)
{
	static char *save;
	char *str;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	ret = BUFF_SIZE;
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (!save)
		save = ft_strnew(BUFF_SIZE);
	if (ft_memchr(save, '\n', ft_strlen(save)))
	{
		if (makeline2(save, &(*line)) == 2)
			return (1);
	}
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
		ft_putstr("\nread : ");
//		ft_putnbr(ret);
//		ft_putstr(*line);
		if (ret < BUFF_SIZE)
		{
			if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(*line) + 1))))
				return (-1);
			ft_strcpy(str, *line);
			*line = NULL;
			if (!(*line = ft_strnew(ft_strlen(str) + ret)))
				return (-1);
			*line = ft_memcpy(*line , str, ret);
		}
			
		if (!(addmal(ret, save)))
			return(-1);
		if (!(save = ft_strjoin(save, *line)))
			return (-1);
		
	//	ft_putstr(save);
		if (ft_memchr(save, '\n', ft_strlen(save)) || ret < BUFF_SIZE)
		{
		//	if ((makeline(ret, save, &(*line)) == 2))
		//	return (1);
		break;
		}
		//ft_putstr("\nil\n");
		//ft_putnbr(ret);
	}
	if (ret == 0)
		return (0);

	if ((ft_memchr(save, '\n', ft_strlen(save)) || (ft_strlen(save) > 0)))
	{
		if ((makeline(ret, save, &(*line)) == 2))
			return (1);
	}
	if (*line == '\0' || save[0] == '\0')
		return (0);
	return (0);
}

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
 }
