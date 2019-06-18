/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   little_fonction.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 16:00:15 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 15:21:31 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

int			ft_memshr(int *tab, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i] >= size)
			return (0);
		i++;
	}
	return (1);
}

void		y_reset(t_tetris *lst)
{
	int i;

	while (lst != NULL)
	{
		i = 0;
		while (i < 4)
		{
			lst->y[i] = lst->tmp_y[i];
			i++;
		}
		lst = lst->next;
	}
}

void		x_reset(t_tetris *lst)
{
	int i;

	while (lst != NULL)
	{
		i = 0;
		while (i < 4)
		{
			lst->x[i] = lst->tmp_x[i];
			i++;
		}
		lst = lst->next;
	}
}

void		ft_increase(int *tab)
{
	int i;

	i = -1;
	while (++i < 4)
		tab[i] += 1;
}

int			ft_ifposible(t_tetris *lst, char **tab, int nb_tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (lst->y[i] >= nb_tab)
			return (FALSE);
		if (tab[lst->y[i]][lst->x[i]] != '.')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
