/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelajour <lelajour@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 14:01:29 by lelajour     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 15:23:46 by lelajour    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/fillit.h"

int		ft_algo(t_tetris *lst, char **tab, int nb_tab)
{
	int i;

	i = 0;
	if (lst == NULL)
		return (TRUE);
	while (putintab(lst, tab, nb_tab) == TRUE)
	{
		is_ok(lst, tab, nb_tab);
		if (ft_algo(lst->next, tab, nb_tab) == TRUE)
			return (TRUE);
		ft_delete(lst, tab, nb_tab);
		ft_increase(lst->x);
	}
	return (FALSE);
}

int		putintab(t_tetris *lst, char **tab, int nb_tab)
{
	while (ft_ifposible(lst, tab, nb_tab) == FALSE)
	{
		ft_increase(lst->x);
		if (ft_memshr(lst->x, nb_tab) == 0)
		{
			x_reset(lst);
			ft_increase(lst->y);
			if (ft_memshr(lst->y, nb_tab) == 0)
			{
				x_reset(lst);
				y_reset(lst);
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

int		is_ok(t_tetris *lst, char **tab, int nb_tab)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (tab[lst->y[i]][lst->x[i]] != '.')
			return (FALSE);
		if (lst->y[i] >= nb_tab || lst->x[i] >= nb_tab)
			return (FALSE);
		tab[lst->y[i]][lst->x[i]] = lst->pause;
	}
	return (TRUE);
}

int		get_next_sqrt(int nb)
{
	int a;
	int sqrtt;

	nb = nb * 4;
	a = 1;
	sqrtt = 0;
	while (a * a <= nb)
	{
		a++;
		sqrtt++;
	}
	return (sqrtt);
}

char	**ft_return(t_tetris *lst, int nb_tetris)
{
	char	**tab;
	int		i;
	int		nb_tab;

	i = 0;
	nb_tab = get_next_sqrt(nb_tetris);
	tab = new_tab(nb_tab);
	while (ft_algo(lst, tab, nb_tab) == FALSE)
	{
		free(tab);
		tab = new_tab(++nb_tab);
	}
	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
	return (tab);
}
