/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   valid_tetri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 09:44:21 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 10:58:10 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

int			valid_tetri(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (str[20] != '\n' && str[20] != 2)
		return (FALSE);
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] != '\0' && str[i + 1] == '#')
				count++;
			if (str[i - 1] >= 0 && str[i - 1] == '#')
				count++;
			if (str[i + 5] != '\0' && str[i + 5] == '#')
				count++;
			if (str[i - 5] >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (TRUE);
	return (FALSE);
}

int			l_check(char *str)
{
	char	buff[21];
	int		ret;
	int		fd;

	ret = 0;
	fd = open(str, O_RDONLY);
	while ((ret = read(fd, buff, 21) >= 20))
	{
		if (valid_tetri(buff) != TRUE)
		{
			close(fd);
			return (FALSE);
		}
	}
	close(fd);
	return (TRUE);
}
