/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit_file_check.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:42:21 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 18:42:47 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

int			check_tetri(char **tab)
{
	int i;
	int s;
	int nb_tetri;
	int nb_h;

	i = 0;
	nb_tetri = 0;
	nb_h = 0;
	while (tab[i])
	{
		s = 0;
		if (i % 4 == 0 && nb_h % 4 == 0)
			nb_tetri++;
		while (tab[i][s] != '\0')
		{
			if (tab[i][s] == '#')
				nb_h++;
			s++;
		}
		if (s != 4)
			return (TRUE);
		i++;
	}
	return (nb_h == nb_tetri * 4 ? nb_tetri : TRUE);
}

int			check_tfile(char **tab)
{
	int i;
	int s;

	i = 0;
	while (tab[i])
	{
		s = 0;
		while (tab[i][s])
		{
			if (s == 4)
				tab[i][s] = '\0';
			if (s > 4)
				return (FALSE);
			s++;
		}
		if (s != 4)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			fillit_read(char str[BUFF_SIZE + 1])
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[0] == '\n') || (str[i] == '\n' && str[i + 2] == '\n'))
			return (FALSE);
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (FALSE);
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			fillit_check_file(char *file)
{
	char	str[BUFF_SIZE + 1];
	int		fd;
	char	**tab;
	int		nb_tetri;

	fd = open(file, O_RDONLY);
	read(fd, str, BUFF_SIZE);
	if (!(fillit_read(str) == TRUE))
		return (TRUE);
	tab = ft_strsplit(str, '\n');
	close(fd);
	if (check_tfile(tab) != TRUE)
		return (TRUE);
	if (!(nb_tetri = check_tetri(tab)) && check_tetri(tab) == 0)
		return (TRUE);
	while (*tab != NULL)
		ft_memdel((void**)tab++);
	return (nb_tetri);
}
