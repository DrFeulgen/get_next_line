/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2018/01/08 15:21:19 by bbataini         ###   ########.fr       */
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

char	addmal(char *line, char *save)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) + BUF_SIZE));
	//	ft_putstr("addma\n");

	tmp = line;
	//	ft_putstr("rth\n");
	while (save[i])
	{
		tmp[i] = save[i];
		i++;
	}
	i = 0;
	while (tmp[i + strlen(save)])
	{
		if (line[i] == '\n')
		{
			return (tmp[i -1]);
		}
		tmp[i + strlen(save)] = line[i];
		i++;
	}
	//	ft_putstr("tmp\n");
	ft_putstr(tmp);
	return (*tmp);
}

int		get_next_line(int const fd, char **line)
{
	//	char **r;
	static char *save;
	int			ret;
	int			i;

	i = 0;
	save = "l";
	ret = 1;
	//	ft_putstr("lkj\n");
	//	line = (char **)malloc(sizeof(char *) * 1);
	//	ft_putstr("ji\n");
	//		ft_putstr("enter\n");
	*line = (char *)malloc(sizeof(char) * BUF_SIZE);
	//		ft_putstr("malloc\n");
	while (ret == read(fd, *line, BUF_SIZE) == 1)
	{
		while (save[i])
		{
			if (*line[i] == '\n')
				return (1);
			i++;
		save = ft_strjoin(save, *line);
		}

		//		ft_putstr("readok\n");
		//		*save = (char *)malloc(sizeof(char) * addmal(*line, save));
		//		ft_putstr("addmalok");
		//		save = ft_addmal(&save);
		//		ft_strcat(save, *line);
		//		ft_save(save);
		ft_putnbr(ret);

		//		ft_putstr("\n");
		//		ft_putstr(*line);
		free(*line);
	}
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
			ft_putstr(line);
		}
	}
	close(fd);
	ft_putstr("outsuccess");
	return (0);
}




