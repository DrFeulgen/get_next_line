/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:41:59 by bbataini          #+#    #+#             */
/*   Updated: 2017/12/21 17:00:01 by bbataini         ###   ########.fr       */
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

char	addmal(char *save)
{
	int i;
	char *tmp;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) + BUF_SIZE));
	tmp = save;
return (i);
}

int		get_next_line(int const fd, char **line)
{
	static char *save;
	int			ret;
	int			i;

	ft_putstr("lkj\n");
	line = (char **)malloc(sizeof(char *) * 1);
	*line = (char *)malloc(sizeof(char) * BUF_SIZE);
	ft_putstr("ji\n");
	if (ret > 0)
	{
		ret = read(fd, *line, BUF_SIZE);
		ft_putstr("un\n");
		save = ft_addmal(&save);

		ft_strcat(save, *line);
		ft_putstr("de\n");
//		ft_save(save);
		ft_putnbr(ret);
		ft_putstr(save);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	char **line;
	int fd;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, line) == 1)
		ac = 1;
		close(fd);
	return (0);
}
