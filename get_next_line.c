/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/02/03 16:36:50 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
   int		ft_save(char *save)
   {
   int i;

   i = 0;

   }
   */

int		addmal(char *save)
{
	char *tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1))))
		return (0);
	//	ft_putstr("addma\n");
	ft_strcpy(tmp, save);
	save = NULL;
	if (!(save = ft_strnew(ft_strlen(tmp) + BUF_SIZE)))
		return(0);
	ft_strcpy(save, tmp);
	return (1);
}

int		makeline(int i, char *save, char **line)
{
	int x;
	int a;

	x = 0;
	a = 0;
	ft_putstr("call\n");
	*line = (char *)malloc(sizeof(char) * i);
	ft_putstr("\n");
	ft_putstr(save);
	if (i != 0 || ft_strlen(save) != 0)
	{

		while (save[x] != '\n')
		{

			*line[x] = save[x];
			x++;
	ft_putstr(*line);
		}
		*line[x] = '\0';
		x++;
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
	//	char **r;
	static char *save;
	int			ret;
	int			i;

	i = 0;
	ret = 1;
	*line = (char *)malloc(sizeof(char) * BUF_SIZE);

	while ((ret = read(fd, *line, BUF_SIZE)) > 0)
	{
		if (!save)
		save = "";
		addmal(save);
		save = ft_strjoin(save, *line);
		makeline(ret, save, &(*line));
		ft_putnbr(ret);
		return (ret);
	}
	
	ft_putnbr(ret);
	return (ret);
}

int		main(int ac, char **av)
{
	char *line;
	int fd;
	//	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putstr("\n");
			//	ft_putstr(line);
		}
	}
	close(fd);
	ft_putstr("outsuccess");
	return (0);
}

