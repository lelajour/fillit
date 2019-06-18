/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit_store.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 09:35:37 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 17:02:35 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

char		**swap_empty(char **tab)
{
	if (ft_strchr(tab[0], '#') == NULL || ft_strchr(tab[1], '#') == NULL)
		ft_swap_col(tab, '#');
	if (ft_colchr(tab, '#') == NULL)
		ft_swap_line(tab);
	return (tab);
}

t_tetris	*pos_tetris(t_tetris *lst)
{
	int i;
	int i_lst;

	i_lst = 0;
	i = 0;
	swap_empty(lst->tetris);
	while (i < (4 * 4))
	{
		if (lst->tetris[i / 4][i % 4] == '#')
		{
			lst->x[i_lst] = (i % 4);
			lst->y[i_lst] = (i / 4);
			i_lst++;
		}
		i++;
	}
	return (lst);
}

t_tetris	*new_l(char *str)
{
	int			i;
	t_tetris	*nw_l;
	char		**tab;

	i = 0;
	if (!(nw_l = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	tab = ft_strsplit(str, '\n');
	if (!(nw_l->tetris = (char**)malloc(sizeof(char*) * 13)))
		return (NULL);
	if (!(nw_l->x = (int*)malloc(sizeof(int) * (4))))
		return (NULL);
	if (!(nw_l->y = (int*)malloc(sizeof(int) * (4))))
		return (NULL);
	while (i < 4)
	{
		if (!(nw_l->tetris[i] = (char*)malloc(sizeof(char)
		* (ft_strlen(tab[i] + 1)))))
			return (NULL);
		nw_l->tetris[i] = ft_memcpy(nw_l->tetris[i], tab[i], ft_strlen(tab[i]));
		i++;
	}
	nw_l->next = NULL;
	nw_l = pos_tetris(nw_l);
	return (nw_l);
}

t_tetris	*fillit_store(char *str)
{
	int			fd;
	t_tetris	*l_list;
	t_tetris	*l_tmp;
	char		buff[21];
	char		a;

	a = 'A';
	if (!(l_list = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	fd = open(str, O_RDONLY);
	read(fd, buff, 21);
	l_list = new_l(buff);
	l_tmp = l_list;
	l_tmp->pause = a++;
	while (read(fd, buff, 21) >= 20)
	{
		l_tmp->next = new_l(buff);
		l_tmp->next->pause = a++;
		l_tmp = l_tmp->next;
	}
	l_tmp->next = NULL;
	return (l_list);
}
